/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for my_radar core functions
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_

    #include <SFML/Graphics.h>
    #include "plane.h"
    #include "tower.h"
    #include "window.h"

    #define MENU_BG_IMG_PATH   "assets/backgrounds/1440p/menu_image_3.jpg"

    int my_radar(char const *file_path);
    int init_simulation(char const *file_path, window_t **window,
                        plane_t ***planes, tower_t ***towers);
    void simulation_loop(window_t *window, plane_t **planes, tower_t **towers);
    void destroy_all(window_t *window, plane_t **planes, tower_t **towers);
    void poll_events(sfRenderWindow *window);
#endif