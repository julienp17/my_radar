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

int my_radar(char const *script_path)
{
    sim_t *sim = sim_create_from_script(script_path);

    if (sim == NULL)
        return (MY_EXIT_FAILURE);
    while (sfRenderWindow_isOpen(sim->window->window)) {
        poll_events(sim);
        if (!(sim->is_paused)) {
            sfRenderWindow_clear(sim->window->window, sfWhite);
            simulation_loop(sim);
            sfRenderWindow_display(sim->window->window);
        }
    }
    sim_destroy(sim);
    return (MY_EXIT_SUCCESS);
}

void simulation_loop(sim_t *sim)
{
    sfRenderWindow_drawSprite(sim->window->window,sim->window->bg_sprite, NULL);
    draw_quadtree(sim->window->window, sim->quadtree);
    draw_towers(sim->window->window, sim->towers);
    for (unsigned int i = 0 ; sim->planes[i] ; i++)
        plane_loop(sim->planes[i], sim);
    draw_timer(sim->window, sim->clock);
}

void plane_loop(plane_t *plane, sim_t *sim)
{
    if (plane->delay > (sfTime_asSeconds(sfClock_getElapsedTime(sim->clock))))
        return;
    sfRenderWindow_drawRectangleShape(sim->window->window, plane->hitbox, NULL);
    if (!(pos_are_near(plane->path->pos, plane->path->end, 10.0)))
        plane_move(plane, plane->path->step);
    else
        plane_reset_random(plane, sim->towers, sim->clock);
}