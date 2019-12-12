/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for simulation structure
*/

#include <stdlib.h>
#include "simulation.h"
#include "file_manipulation.h"
#include "usage.h"

sim_t *simulation_create(char const *file_path)
{
    sim_t *sim = malloc(sizeof(*sim));

    sim->window = window_create(W_WIDTH, W_HEIGHT, W_TITLE);
    sim->plane_ctn = malloc(sizeof(*(sim->plane_ctn)));
    sim->tower_ctn = malloc(sizeof(*(sim->tower_ctn)));
    sim->plane_ctn->planes = NULL;
    sim->tower_ctn->towers = NULL;
    sim->plane_ctn->texture = sfTexture_createFromFile(TOWER_TEXTURE_PATH, )

    if (get_entities_from_file(file_path, &(sim->plane_ctn->planes),
                            &(sim->tower_ctn->towers)) == -1) {
        return (MY_EXIT_FAILURE);
    }
}