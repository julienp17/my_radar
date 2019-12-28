/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for airplane structure
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "plane.h"
#include "utils.h"

plane_t *plane_create(path_t *path, sfTexture *texture, unsigned int delay)
{
    plane_t *plane = malloc(sizeof(*plane));

    if (!plane)
        return (NULL);
    plane->path   = path;
    plane->delay  = delay;
    plane->hitbox = sfRectangleShape_create();
    if (!(plane->hitbox))
        return (NULL);
    sfRectangleShape_setSize(plane->hitbox, (sfVector2f) {20.0, 20.0});
    sfRectangleShape_setOutlineColor(plane->hitbox, sfYellow);
    sfRectangleShape_setOutlineThickness(plane->hitbox, 2.0);
    sfRectangleShape_setTexture(plane->hitbox, texture, sfTrue);
    sfRectangleShape_setPosition(plane->hitbox, plane->path->pos);
    sfRectangleShape_rotate(plane->hitbox,
                get_angle_from_coordinate(plane->path->end, plane->path->pos));
    return (plane);
}

void plane_destroy(plane_t *plane)
{
    if (plane->path)
        free(plane->path);
    if (plane->hitbox)
        sfRectangleShape_destroy(plane->hitbox);
    if (plane)
        free(plane);
}

void plane_move(plane_t *plane, sfVector2f const offset)
{
    plane->path->pos.x  += offset.x;
    plane->path->pos.y  += offset.y;
    plane->path->diff.x -= abs((int)(offset.x));
    plane->path->diff.y -= abs((int)(offset.y));
    sfRectangleShape_move(plane->hitbox, offset);
}

void plane_reset_random(plane_t *plane, tower_t **towers, sfClock *clock)
{
    sfInt32 c_time = sfTime_asSeconds(sfClock_getElapsedTime(clock));
    sfVector2f new_beg;
    sfVector2f new_end;
    unsigned int new_speed = rand() % (6 + 1 - 3) + 3;

    if (plane->path)
        free(plane->path);
    new_beg = get_random_tower_pos(towers);
    new_end = get_random_tower_pos(towers);
    while (pos_match(new_beg, new_end))
        new_end = get_random_tower_pos(towers);
    plane->delay = c_time + rand() % 10;
    plane->path = path_create(new_beg, new_end, new_speed);
    sfRectangleShape_setPosition(plane->hitbox, plane->path->pos);
    sfRectangleShape_setRotation(plane->hitbox, 0.0);
    sfRectangleShape_rotate(plane->hitbox,
                get_angle_from_coordinate(plane->path->end, plane->path->pos));
}