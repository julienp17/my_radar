/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for airplane structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "plane.h"

plane_t *plane_create(sfVector2f departure, sfVector2f arrival,
                    unsigned int speed, unsigned int delay)
{
    plane_t *plane   = malloc(sizeof(*plane));

    plane->pos       = departure;
    plane->end       = arrival;
    plane->rect      = (sfIntRect) {departure.x, departure.y, 20, 20};
    plane->speed     = speed;
    plane->delay     = delay;
    plane->step      = get_step_offset(departure, arrival);
    plane->step.x   *= speed;
    plane->step.y   *= speed;
    plane->texture   = sfTexture_createFromFile(PLANE_TEXTURE_PATH, NULL);
    plane->sprite    = sfSprite_create();
    sfSprite_setTexture(plane->sprite, plane->texture, sfTrue);
    sfSprite_setPosition(plane->sprite, plane->pos);
    return (plane);
}

void plane_update_pos(plane_t *plane)
{
    unsigned int x_diff = abs((int)(plane->end.x) - (int)(plane->pos.x));
    unsigned int y_diff = abs((int)(plane->end.y) - (int)(plane->pos.y));

    if (x_diff > 1 && y_diff > 1) {
        plane->pos.x += plane->step.x;
        plane->pos.y += plane->step.y;
        sfSprite_move(plane->sprite, plane->step);
    }
}

sfVector2f get_step_offset(sfVector2f point_a, sfVector2f point_b)
{
    int dx = point_b.x - point_a.x;
    int dy = point_b.y - point_a.y;
    unsigned int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    sfVector2f offset;

    offset.x = dx / (float)steps;
    offset.y = dy / (float)steps;
    return (offset);
}