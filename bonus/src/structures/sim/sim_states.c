/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Source file for structure sim_states
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "sim_states.h"

sim_states_t *sim_states_create(void)
{
    sim_states_t *states = malloc(sizeof(sim_states_t));

    if (!states)
        return (NULL);
    states->show_hitbox = sfTrue;
    states->show_sprites = sfFalse;
    states->show_quadtree = sfFalse;
    states->show_info = sfFalse;
    states->is_paused = sfFalse;
    return (states);
}

void sim_states_destroy(sim_states_t *states)
{
    if (states)
        free(states);
}