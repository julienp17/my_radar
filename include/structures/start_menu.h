/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <SFML/Graphics.h>
    #include "window.h"
    #include "button.h"

    #define MENU_BG_IMG_PATH    "assets/backgrounds/1440p/menu_image.jpg"

    typedef struct menu {
        window_t *window;
        button_t *start;
        button_t *quit;
    } start_menu_t;

    start_menu_t *start_menu_create(void);
    void start_menu_destroy(start_menu_t *menu);

    int start_menu(void);
    void draw_start_menu(start_menu_t *menu);
#endif