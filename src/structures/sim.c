/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for simulation structure
*/

#include <stdlib.h>
#include <SFML/System.h>
#include "sim.h"
#include "file_manipulation.h"
#include "window.h"
#include "plane.h"
#include "tower.h"

sim_t *sim_create_from_script(char const *filepath)
{
    sim_t *sim = malloc(sizeof(sim_t));

    if (!sim)
        return (NULL);
    sim->window = window_create(W_WIDTH, W_HEIGHT, W_TITLE, SIM_BG_IMG_PATH);
    sim->clock  = sfClock_create();
    sim->is_paused = sfFalse;
    sim->plane_texture = sfTexture_createFromFile(SIM_PLANE_TEXTURE_PATH, NULL);
    sim->tower_texture = sfTexture_createFromFile(SIM_TOWER_TEXTURE_PATH, NULL);
    sim->planes = NULL;
    sim->towers = NULL;
    if (!(sim->window) || !(sim->plane_texture) || !(sim->tower_texture))
        return (NULL);
    if (get_entities_from_file(filepath, sim) == -1)
        return (NULL);
    return (sim);
}

void sim_destroy(sim_t *sim)
{
    if (sim->window)
        window_destroy(sim->window);
    for (unsigned int i = 0 ; sim->towers[i] ; i++)
        tower_destroy(sim->towers[i]);
    for (unsigned int i = 0 ; sim->planes[i] ; i++)
        plane_destroy(sim->planes[i]);
    if (sim->plane_texture)
        sfTexture_destroy(sim->plane_texture);
    if (sim->tower_texture)
        sfTexture_destroy(sim->tower_texture);
    if (sim)
        free(sim);
}