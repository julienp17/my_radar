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

sim_t *sim_create(void)
{
    sim_t *sim = malloc(sizeof(sim_t));

    if (!sim)
        return (NULL);
    sim->textures = sim_textures_create();
    sim->fonts = sim_fonts_create();
    sim->window = window_create(W_WIDTH, W_HEIGHT, W_TITLE);
    sim->quadtree = quadtree_create((sfIntRect) {0, 0, W_WIDTH, W_HEIGHT});
    sim->clock = sfClock_create();
    sim->is_paused = sfFalse;
    sim->planes = NULL;
    sim->towers = NULL;
    if (!(sim->textures) || (!sim->window) || !(sim->quadtree) || (!sim->clock))
        return (NULL);
    return (sim);
}

sim_t *sim_create_from_script(char const *filepath)
{
    sim_t *sim = sim_create();

    if (!sim)
        return (NULL);
    if (get_entities_from_file(filepath, sim) != 0)
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
    if (sim->quadtree) {
        quadtree_clear(sim->quadtree);
        free(sim->quadtree);
    }
    if (sim->clock)
        sfClock_destroy(sim->clock);
    if (sim->textures)
        sim_textures_destroy(sim->textures);
    if (sim->fonts)
        sim_fonts_destroy(sim->fonts);
    if (sim)
        free(sim);
}