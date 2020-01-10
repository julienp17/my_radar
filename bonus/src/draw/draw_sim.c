/*
** EPITECH PROJECT, 2020
** bonus
** File description:
** draw_sim
*/

#include "my_radar.h"
#include "sim.h"
#include "draw.h"

void draw_sim(sim_t *sim)
{
    draw_background(sim->gl->window, sim->gl->window->background,
                    sim->gl->timelapse);
    draw_towers(sim->gl->window->render, sim->towers, sim->state);
    draw_quadtree(sim->gl->window->render, sim->quadtree, sim->state);
    for (unsigned int i = 0 ; sim->planes[i] ; i++)
        plane_loop(sim->planes[i], sim, sim->info->timer);
    draw_timer(sim->gl->window->render, sim->gl->texts->timer,sim->info->timer);
    draw_info(sim->gl->window->render, sim->info, sim->gl->texts, sim->state);
}