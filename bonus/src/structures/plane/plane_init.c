/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** plane_init
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "my_radar.h"
#include "plane.h"

static void plane_rotate(plane_t *plane, uint w_width);
static float plane_get_angle_by_path(plane_t *plane, uint w_width);

plane_t *plane_init(plane_t *plane, path_t *path, uint delay, uint w_width)
{
    plane->delay = delay;
    plane->path = path;
    sfSprite_setPosition(plane->sprite, plane->path->pos);
    sfSprite_move(plane->sprite, (sfVector2f) {10, 10});
    plane_rotate(plane, w_width);
    sfRectangleShape_setPosition(plane->outline, (sfVector2f)
                                {plane->hitbox.left, plane->hitbox.top});
    sfRectangleShape_setSize(plane->outline, (sfVector2f)
                                {plane->hitbox.width, plane->hitbox.height});
    return (plane);
}

static void plane_rotate(plane_t *plane, uint w_width)
{
    sfFloatRect hitbox = {plane->path->pos.x, plane->path->pos.y,
                        PLANE_SPRITE_SIZE, PLANE_SPRITE_SIZE};

    sfSprite_setRotation(plane->sprite, 0.0);
    plane->angle = plane_get_angle_by_path(plane, w_width);
    sfSprite_rotate(plane->sprite, plane->angle);
    plane->hitbox = hitbox;
    plane->hitbox = get_bounding_box_of_rotated(plane->hitbox, plane->angle);
}

static float plane_get_angle_by_path(plane_t *plane, uint w_width)
{
    sfVector2f plane_beg = plane->path->pos;
    float x_diff = plane->path->end.x - plane->path->pos.x;

    if ((plane->path->step.x < 0) != (x_diff < 0)) {
        if ((plane->path->step.x < 0) && (x_diff > 0))
            plane_beg.x += w_width;
        else
            plane_beg.x -= w_width;
    }
    return (get_angle_from_coordinate(plane->path->end, plane_beg));
}

void plane_reset_random(plane_t *plane, tower_t **towers,
                        uint c_time, uint w_width)
{
    path_t *new_path = NULL;
    unsigned int new_delay = 0;

    if (plane->path)
        free(plane->path);
    new_path = get_random_path(towers, w_width);
    new_delay = c_time + rand() % 20;
    plane = plane_init(plane, new_path, new_delay, w_width);
}