/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for structure sim_textures
*/

#ifndef TEXTURES_H_
    #define TEXTURES_H_

    #include <SFML/Graphics.h>

    #define BACKGROUND_TEXTURE_PATH  "assets/backgrounds/1440p/world_map.png"
    #define PLANE_TEXTURE_PATH       "assets/textures/plane2_small.png"
    #define TOWER_TEXTURE_PATH       "assets/textures/tower_small.png"

    typedef struct sim_textures {
        sfTexture *plane;
        sfTexture *tower;
        sfTexture *background;
    } sim_textures_t;

    sim_textures_t *sim_textures_create(void);
    void sim_textures_destroy(sim_textures_t *);
#endif