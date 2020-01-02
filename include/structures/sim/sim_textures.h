/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for structure sim_textures
*/

#ifndef TEXTURES_H_
    #define TEXTURES_H_

    #include <SFML/Graphics.h>

    #define START_MENU_BG_TEXTURE_PATH "assets/backgrounds/start_menu.png"
    #define SIM_BG_TEXTURE_PATH        "assets/backgrounds/world_map.png"
    #define PLANE_TEXTURE_PATH         "assets/textures/plane.png"
    #define TOWER_TEXTURE_PATH         "assets/textures/tower.png"

    typedef sfTexture texture_t;

    typedef struct sim_textures {
        texture_t *start_menu_bg;
        texture_t *sim_bg;
        texture_t *plane;
        texture_t *tower;
    } sim_textures_t;
    typedef sim_textures_t textures_t;

    sim_textures_t *sim_textures_create(void);
    void sim_textures_destroy(sim_textures_t *);
#endif