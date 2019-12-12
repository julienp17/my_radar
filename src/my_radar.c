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
#include "file_manipulation.h"
#include "window.h"
#include "plane.h"
#include "tower.h"

// void draw_towers(sfRenderWindow *window, tower_t **towers);
// static void init_towers(sfTexture **texture, sfSprite **sprite,
//                         sfCircleShape **control_area);

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
    (void)planes;
    (void)towers;
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window);
        sfRenderWindow_clear(window->window, sfWhite);
        sfRenderWindow_drawSprite(window->window, window->background_sprite,
                                    NULL);
        sfRenderWindow_display(window->window);
    }
}

void poll_events(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event))
        if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
}

void destroy_all(window_t *window, plane_t **planes, tower_t **towers)
{
    window_destroy(window);
    for (unsigned int i = 0 ; planes[i] ; i++)
        free(planes[i]);
    for (unsigned int i = 0 ; towers[i] ; i++)
        free(towers[i]);
}

// void draw_towers(sfRenderWindow *window, tower_t **towers)
// {
//     static bool first_run = true;
//     static sfTexture *tower_texture = NULL;
//     static sfSprite *tower_sprite = NULL;
//     static sfCircleShape *control_area = NULL;
//     sfVector2f tower_pos;

//     if (first_run) {
//         init_towers(&tower_texture, &tower_sprite, &control_area);
//         first_run = false;
//     }
//     for (unsigned int i = 0 ; towers[i] ; i++) {
//         tower_pos.x = towers[i]->pos.x;
//         tower_pos.y = towers[i]->pos.y;
//         if (!tower_sprite)
//             printf("tower_sprite is NUll\n");
//         sfSprite_setPosition(tower_sprite, tower_pos);
//         sfCircleShape_setRadius(control_area, towers[i]->radius);
//         sfCircleShape_setPosition(control_area, tower_pos);
//         sfRenderWindow_drawSprite(window, tower_sprite, NULL);
//         sfRenderWindow_drawCircleShape(window, control_area, NULL);
//     }
// }

// static void init_towers(sfTexture **texture, sfSprite **sprite,
//                         sfCircleShape **control_area)
// {
//     sfIntRect pos = {0, 0, 1366, 768};

//     *texture = sfTexture_createFromFile("assets/tower_small.png", &pos);
//     *sprite = sfSprite_create();
//     *control_area = sfCircleShape_create();
//     sfSprite_setTexture(*sprite, *texture, sfTrue);
//     sfCircleShape_setFillColor(*control_area, sfTransparent);
//     sfCircleShape_setOutlineColor(*control_area, sfBlue);
//     sfCircleShape_setOutlineThickness(*control_area, 2);
// }