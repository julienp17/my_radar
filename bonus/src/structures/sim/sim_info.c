/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Source file for structure sim_info
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "sim_info.h"

sim_info_t *sim_info_create(void)
{
    sim_info_t *info = malloc(sizeof(sim_info_t));

    if (!info)
        return (NULL);
    info->nb_planes = 0;
    info->nb_planes_flying = 0;
    info->nb_towers = 0;
    info->timer = 0;
    return (info);
}

void sim_info_destroy(sim_info_t *info)
{
    if (info)
        free(info);
}