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
#include "draw.h"
#include "file_manipulation.h"
#include "sim.h"

int my_radar(char const *script_path)
{
    sim_t *sim = sim_create_from_script(script_path);

    if (sim == NULL)
        return (MY_EXIT_FAILURE);
    while (sfRenderWindow_isOpen(sim->window->window)) {
        window_poll_quit(sim->window->window);
        sfRenderWindow_clear(sim->window->window, sfWhite);
        simulation_loop(sim);
        sfRenderWindow_display(sim->window->window);
    }
    sim_destroy(sim);
    return (MY_EXIT_SUCCESS);
}

void simulation_loop(sim_t *sim)
{
    sfRenderWindow_drawSprite(sim->window->window,sim->window->bg_sprite, NULL);
    draw_towers(sim->window->window, sim->towers);
    draw_planes(sim->window->window, sim->planes);
}