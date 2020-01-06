/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** simulation
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "usage.h"
#include "my_radar.h"
#include "sim.h"
#include "draw.h"
#include "events.h"
#include "utils.h"
#include "collisions.h"
#include "my.h"

int launch_simulation(window_t *window, char const *script_path)
{
    sim_t *sim = NULL;

    if ((sim = sim_create_from_script(window, script_path)) == NULL) {
        my_puterr("Simulation couldn't be created.\n");
        return (MY_EXIT_FAILURE);
    }
    window_set_background(sim->gl->window, sim->gl->textures->sim_bg_day);
    while (sfRenderWindow_isOpen(sim->gl->window->render)) {
        sim_poll_events(sim->gl->window, sim->state);
        if (!(sim->state->is_paused)) {
            sfRenderWindow_clear(sim->gl->window->render, sfWhite);
            simulation_loop(sim);
            sfRenderWindow_display(sim->gl->window->render);
        }
    }
    sim_destroy(sim);
    return (MY_EXIT_SUCCESS);
}

void simulation_loop(sim_t *sim)
{
    uint c_time = sfTime_asSeconds(sfClock_getElapsedTime(sim->clock));

    quadtree_clear(sim->quadtree);
    insert_planes_in_quadtree(sim->planes, sim->quadtree, c_time);
    draw_background(sim->gl->window->render, sim->gl->window->background);
    draw_towers(sim->gl->window->render, sim->towers, sim->state);
    draw_quadtree(sim->gl->window->render, sim->quadtree, sim->state);
    for (unsigned int i = 0 ; sim->planes[i] ; i++)
        plane_loop(sim->planes[i], sim, c_time);
    draw_timer(sim->gl->window->render, sim->gl->texts->timer, c_time);
}

void plane_loop(plane_t *plane, sim_t *sim, uint c_time)
{
    plane_t *c_plane = NULL;

    if (plane->delay > c_time)
        return;
    c_plane = get_collided_plane(plane, sim->towers, sim->quadtree);
    if (c_plane) {
        plane_reset_random(plane, sim->towers, c_time, sim->gl->window->width);
        plane_reset_random(c_plane, sim->towers, c_time,sim->gl->window->width);
        return;
    }
    draw_plane(sim->gl->window->render, plane, sim->state);
    plane_move(plane, plane->path->step, sim->gl->window->width);
    if (pos_are_near(plane->path->pos, plane->path->end, 10.0))
        plane_reset_random(plane, sim->towers, c_time, sim->gl->window->width);
}

void insert_planes_in_quadtree(plane_t **planes, quadtree_t *quadtree,
                                uint c_time)
{
    for (unsigned int i = 0 ; planes[i] ; i++)
        if (planes[i]->delay <= c_time)
            quadtree_insert(quadtree, planes[i]);
}