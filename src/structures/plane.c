/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for airplane structure
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "plane.h"

plane_t *plane_create(path_t *path, sfTexture *texture, unsigned int delay)
{
    plane_t *plane = malloc(sizeof(*plane));

    if (!plane)
        return (NULL);
    plane->path   = path;
    plane->delay  = delay;
    plane->sprite = sfSprite_create();
    sfSprite_setTexture(plane->sprite, texture, sfTrue);
    sfSprite_setPosition(plane->sprite, plane->path->pos);
    sfSprite_rotate(plane->sprite,
                get_angle_from_coordinate(plane->path->end, plane->path->pos));
    return (plane);
}

void plane_destroy(plane_t *plane)
{
    if (plane->path)
        free(plane->path);
    if (plane->sprite)
        sfSprite_destroy(plane->sprite);
    if (plane)
        free(plane);
}

void plane_update_pos(plane_t *plane)
{
    if (plane->path->diff.x > 1 && plane->path->diff.y > 1) {
        plane->path->pos.x  += plane->path->step.x;
        plane->path->pos.y  += plane->path->step.y;
        plane->path->diff.x += plane->path->step.x;
        plane->path->diff.y += plane->path->step.y;
        sfSprite_move(plane->sprite, plane->path->step);
    }
}

float get_angle_from_coordinate(sfVector2f point_a, sfVector2f point_b)
{
    float dx = point_b.x - point_a.x;
    float dy = point_b.y - point_a.y;
    float radians = atan2f(dx, dy);

    if (radians < 0.0)
        radians = fabs(radians);
    else
        radians = 2 * M_PI - radians;
    return (180.0 / M_PI * radians);
}