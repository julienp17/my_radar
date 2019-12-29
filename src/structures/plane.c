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

static plane_t *plane_init(plane_t *plane, path_t *path, unsigned int delay);

plane_t *plane_create(path_t *path, sfTexture *texture, unsigned int delay)
{
    plane_t *plane = malloc(sizeof(*plane));

    if (!plane)
        return (NULL);
    plane->sprite = sfSprite_create();
    plane->outline = sfRectangleShape_create();
    if (!(plane->sprite) || !(plane->outline))
        return (NULL);
    sfSprite_setTexture(plane->sprite, texture, sfTrue);
    sfSprite_setOrigin(plane->sprite, (sfVector2f) {10, 10});
    sfRectangleShape_setFillColor(plane->outline, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->outline, sfYellow);
    sfRectangleShape_setOutlineThickness(plane->outline, 2.0);
    return (plane_init(plane, path, delay));
}

static plane_t *plane_init(plane_t *plane, path_t *path, unsigned int delay)
{
    plane->delay = delay;
    plane->path = path;
    plane->angle = get_angle_from_coordinate(plane->path->end,plane->path->pos);
    sfSprite_setPosition(plane->sprite, plane->path->pos);
    sfSprite_setRotation(plane->sprite, 0.0);
    sfSprite_move(plane->sprite, (sfVector2f) {10, 10});
    sfSprite_rotate(plane->sprite, plane->angle);
    plane->hitbox = (sfIntRect) {(int)plane->path->pos.x,
                                (int)plane->path->pos.y, 20,20};
    plane->hitbox = get_bounding_box_of_rotated(plane->hitbox, plane->angle);
    sfRectangleShape_setPosition(plane->outline, (sfVector2f)
                                {plane->hitbox.left, plane->hitbox.top});
    sfRectangleShape_setSize(plane->outline, (sfVector2f)
                                {plane->hitbox.width, plane->hitbox.height});
    return (plane);
}

void plane_destroy(plane_t *plane)
{
    if (plane->path)
        free(plane->path);
    if (plane->sprite)
        sfSprite_destroy(plane->sprite);
    if (plane->outline)
        sfRectangleShape_destroy(plane->outline);
    if (plane)
        free(plane);
}

void plane_move(plane_t *plane, sfVector2f const offset)
{
    plane->path->pos.x  += offset.x;
    plane->path->pos.y  += offset.y;
    plane->hitbox.left  += offset.x;
    plane->hitbox.top += offset.y;
    sfSprite_move(plane->sprite, offset);
    sfRectangleShape_move(plane->outline, offset);
}

void plane_reset_random(plane_t *plane, tower_t **towers, sfClock *clock)
{
    path_t *new_path = NULL;
    unsigned int new_delay = 0;

    if (plane->path)
        free(plane->path);
    new_path = get_random_path(towers);
    new_delay = sfTime_asSeconds(sfClock_getElapsedTime(clock)) + rand() % 10;
    plane = plane_init(plane, new_path, new_delay);
}