/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Functions to draw on the screen
*/

#include <SFML/Graphics.h>
#include "window.h"
#include "tower.h"
#include "plane.h"
#include "quadtree.h"
#include "my.h"

static void draw_quadtree_recursively(sfRenderWindow *window,
                            quadtree_t *quadtree, sfRectangleShape *boundary);

void draw_towers(sfRenderWindow *window, tower_t **towers)
{
    for (unsigned int i = 0 ; towers[i] ; i++) {
        sfRenderWindow_drawSprite(window, towers[i]->sprite, NULL);
        sfRenderWindow_drawCircleShape(window, towers[i]->control_area, NULL);
    }
}

void draw_quadtree(sfRenderWindow *window, quadtree_t *quadtree)
{
    sfRectangleShape *boundary = sfRectangleShape_create();

    sfRectangleShape_setFillColor(boundary, sfTransparent);
    sfRectangleShape_setOutlineColor(boundary, sfWhite);
    sfRectangleShape_setOutlineThickness(boundary, 2.0);
    draw_quadtree_recursively(window, quadtree, boundary);
    sfRectangleShape_destroy(boundary);
}

static void draw_quadtree_recursively(sfRenderWindow *window,
                            quadtree_t *quadtree, sfRectangleShape *boundary)
{
    sfVector2f boundary_pos  = {quadtree->boundary.left,
                                quadtree->boundary.top};
    sfVector2f boundary_size = {quadtree->boundary.width,
                                quadtree->boundary.height};

    sfRectangleShape_setPosition(boundary, boundary_pos);
    sfRectangleShape_setSize(boundary, boundary_size);
    sfRenderWindow_drawRectangleShape(window, boundary, NULL);
    if (quadtree->is_divided)
        for (unsigned int i = 0 ; i < 4 ; i++)
            draw_quadtree_recursively(window, quadtree->children[i], boundary);
}

void draw_pause_menu(window_t *window)
{
    sfRectangleShape *pause_menu = sfRectangleShape_create();
    sfColor pause_color = (sfColor) {50, 50, 50, 125};
    sfVector2f window_size = (sfVector2f) {window->width, window->height};

    sfRectangleShape_setFillColor(pause_menu, pause_color);
    sfRectangleShape_setSize(pause_menu, window_size);
    sfRenderWindow_drawRectangleShape(window->window, pause_menu, NULL);
    sfRenderWindow_display(window->window);
    sfRectangleShape_destroy(pause_menu);
}

void draw_timer(window_t *window, sfClock *clock)
{
    sfInt32 time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfText *str_time = sfText_create();
    sfVector2f pos = {window->width - 100, 0};
    sfFont *font = sfFont_createFromFile("assets/fonts/skyfont.otf");

    sfText_setCharacterSize(str_time, 100);
    sfText_setFont(str_time, font);
    sfText_setColor(str_time, sfBlack);
    sfText_setString(str_time, my_int_to_strnum(time));
    sfText_setPosition(str_time, pos);
    sfRenderWindow_drawText(window->window, str_time, NULL);
    sfText_destroy(str_time);
    sfFont_destroy(font);
}