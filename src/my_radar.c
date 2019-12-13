/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** simulation
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "usage.h"
#include "my_radar.h"
#include "draw.h"
#include "file_manipulation.h"
#include "window.h"
#include "plane.h"
#include "tower.h"

int my_radar(char const *file_path)
{
    window_t *window = NULL;
    plane_t **planes = NULL;
    tower_t **towers = NULL;

    if (init_simulation(file_path, &window, &planes,&towers) == MY_EXIT_FAILURE)
        return (MY_EXIT_FAILURE);
    simulation_loop(window, planes, towers);
    destroy_all(window, planes, towers);
    return (MY_EXIT_SUCCESS);
}

int init_simulation(char const *file_path, window_t **window, plane_t ***planes,
                    tower_t ***towers)
{
    *window = window_create(W_WIDTH, W_HEIGHT, W_TITLE);

    if (!(*window))
        return (MY_EXIT_FAILURE);
    if (get_entities_from_file(file_path, planes, towers) == -1)
        return (MY_EXIT_FAILURE);
    return (MY_EXIT_SUCCESS);
}

void simulation_loop(window_t *window, plane_t **planes, tower_t **towers)
{
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        sfRenderWindow_clear(window->window, sfWhite);
        sfRenderWindow_drawSprite(window->window, window->background_sprite,
                                    NULL);
        draw_towers(window->window, towers);
        draw_planes(window->window, planes);
        sfRenderWindow_display(window->window);
    }
}

void poll_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.key.code == sfKeyEscape || event.key.code == sfKeyQ)
            sfRenderWindow_close(window);
    }
}

void destroy_all(window_t *window, plane_t **planes, tower_t **towers)
{
    window_destroy(window);
    for (unsigned int i = 0 ; planes[i] ; i++)
        free(planes[i]);
    for (unsigned int i = 0 ; towers[i] ; i++)
        tower_destroy(towers[i]);
}