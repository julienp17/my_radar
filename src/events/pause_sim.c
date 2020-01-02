/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** pause_sim
*/

#include <SFML/Graphics.h>
#include "sim.h"
#include "draw.h"

void pause_sim(sim_t *sim)
{
    if (sim->is_paused) {
        sim->is_paused = sfFalse;
    } else {
        draw_pause_menu(sim->window);
        sim->is_paused = sfTrue;
    }
}