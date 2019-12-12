/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** simulation
*/

#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include "file_manipulation.h"
#include "tower.h"
#include "window.h"
#include "plane.h"
#include "usage.h"

void poll_events(sfRenderWindow *window, sfEvent *event);
// void draw_towers(sfRenderWindow *window, tower_t **towers);
// static void init_towers(sfTexture **texture, sfSprite **sprite,
//                         sfCircleShape **control_area);

int launch_simulation(char const *file_path)
{
    sim_t = simulation_create(file_path);
    window_t *window = window_create(W_WIDTH, W_HEIGHT, W_TITLE);
    plane_t **planes = NULL;
    tower_t **towers = NULL;
    sfEvent event;

    if (get_entities_from_file(file_path, &planes, &towers) == -1)
        return (MY_EXIT_FAILURE);
    while (sfRenderWindow_isOpen(window->window)) {
        poll_events(window->window, &event);
        sfRenderWindow_clear(window->window, sfWhite);
        sfRenderWindow_drawSprite(window->window, window->background_sprite,
                                    NULL);
        sfRenderWindow_display(window->window);
    }
    window_destroy(window);
    return (MY_EXIT_SUCCESS);
}

void poll_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event))
        if (event->type == sfEvtClosed || event->key.code == sfKeyEscape)
            sfRenderWindow_close(window);
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