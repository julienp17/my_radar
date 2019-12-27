/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for simulation structure
*/

#ifndef SIM_H_
    #define SIM_H_

    #include "window.h"
    #include "plane.h"
    #include "tower.h"

    #define SIM_BG_IMG_PATH        "assets/backgrounds/real_world_map_small.png"
    #define SIM_PLANE_TEXTURE_PATH "assets/textures/plane2_small.png"
    #define SIM_TOWER_TEXTURE_PATH "assets/textures/tower_small.png"

    typedef struct simulation {
        window_t *window;
        plane_t **planes;
        tower_t **towers;
        sfTexture *plane_texture;
        sfTexture *tower_texture;
    } sim_t;

    sim_t *sim_create_from_script(char const *filepath);
    void sim_destroy(sim_t *sim);
#endif