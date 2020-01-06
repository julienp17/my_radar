/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for path structure
*/

#include <stdlib.h>
#include <math.h>
#include <SFML/Graphics.h>
#include "path.h"
#include "utils.h"
#include "math.h"

path_t *path_create(sfVector2f beg, sfVector2f end, uint speed, uint w_width)
{
    path_t *path = malloc(sizeof(*path));
    sfVector2f alt_pos = beg;

    if (!path)
        return (NULL);
    alt_pos.x += (beg.x < end.x) ? (int)w_width : -((int)w_width);
    path->pos = beg;
    path->end = end;
    if (fabs(end.x - beg.x) <= fabs(end.x - alt_pos.x))
        path->step = get_step_offset(beg, end);
    else
        path->step = get_step_offset(alt_pos, end);
    path->step.x *= speed;
    path->step.y *= speed;
    return (path);
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

path_t *get_random_path(tower_t **towers, uint w_width)
{
    sfVector2f beg;
    sfVector2f end;
    unsigned int speed = rand() % (6 + 1 - 3) + 3;

    beg = get_random_tower_pos(towers);
    end = get_random_tower_pos(towers);
    while (pos_match(beg, end))
        end = get_random_tower_pos(towers);
    return (path_create(beg, end, speed, w_width));
}