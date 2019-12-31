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

void launch_simulation(sim_t *sim)
{
    while (sfRenderWindow_isOpen(sim->window->window)) {
        sim_poll_events(sim);
        if (!(sim->is_paused)) {
            sfRenderWindow_clear(sim->window->window, sfWhite);
            simulation_loop(sim);
            sfRenderWindow_display(sim->window->window);
        }
    }
}

void simulation_loop(sim_t *sim)
{
    unsigned int c_time = sfTime_asSeconds(sfClock_getElapsedTime(sim->clock));

    quadtree_clear(sim->quadtree);
    insert_planes_in_quadtree(sim->planes, sim->quadtree, c_time);
    sfRenderWindow_drawSprite(sim->window->window,sim->window->bg_sprite, NULL);
    draw_towers(sim->window->window, sim->towers);
    for (unsigned int i = 0 ; sim->planes[i] ; i++)
        plane_loop(sim->planes[i], sim, c_time);
}

void plane_loop(plane_t *plane, sim_t *sim, unsigned int c_time)
{
    plane_t *coll_plane = NULL;

    if (plane->delay > c_time)
        return;
    coll_plane = get_collided_plane(plane, sim->towers, sim->quadtree);
    if (coll_plane) {
        plane_reset_random(plane, sim->towers, c_time, sim->window->width);
        plane_reset_random(coll_plane, sim->towers, c_time, sim->window->width);
        return;
    }
    sfRenderWindow_drawSprite(sim->window->window, plane->sprite, NULL);
    sfRenderWindow_drawRectangleShape(sim->window->window,plane->outline, NULL);
    plane_move(plane, plane->path->step, sim->window->width);
    if (pos_are_near(plane->path->pos, plane->path->end, 10.0))
        plane_reset_random(plane, sim->towers, c_time, sim->window->width);
}

void insert_planes_in_quadtree(plane_t **planes, quadtree_t *quadtree,
                            unsigned int c_time)
{
    for (unsigned int i = 0 ; planes[i] ; i++)
        if (planes[i]->delay <= c_time)
            quadtree_insert(quadtree, planes[i]);
}