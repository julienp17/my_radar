/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for structure sim_textures
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "sim_textures.h"

sim_textures_t *sim_textures_create(void)
{
    sim_textures_t *textures = malloc(sizeof(sim_textures_t));

    if (!textures)
        return (NULL);
    textures->plane = sfTexture_createFromFile(PLANE_TEXTURE_PATH, NULL);
    textures->tower = sfTexture_createFromFile(TOWER_TEXTURE_PATH, NULL);
    textures->sim_bg_day = sfTexture_createFromFile(SIM_BG_DAY_TEXTURE_PATH,
                                                    NULL);
    textures->sim_bg_night = sfTexture_createFromFile(SIM_BG_NIGHT_TEXTURE_PATH,
                                                    NULL);
    if (!(textures->plane) || !(textures->tower))
        return (NULL);
    if (!(textures->sim_bg_day) || !(textures->sim_bg_night))
        return (NULL);
    return (textures);
}

void sim_textures_destroy(sim_textures_t *textures)
{
    if (textures->plane)
        sfTexture_destroy(textures->plane);
    if (textures->tower)
        sfTexture_destroy(textures->tower);
    if (textures->sim_bg_day)
        sfTexture_destroy(textures->sim_bg_day);
    if (textures->sim_bg_night)
        sfTexture_destroy(textures->sim_bg_night);
    if (textures)
        free(textures);
}