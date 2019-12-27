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

path_t *path_create(sfVector2f beg, sfVector2f end, unsigned int speed)
{
    path_t *path = malloc(sizeof(*path));

    if (!path)
        return (NULL);
    path->pos     = beg;
    path->end     = end;
    path->diff.x  = abs((int)end.x - (int)beg.x);
    path->diff.y  = abs((int)end.y - (int)beg.y);
    path->step    = get_step_offset(beg, end);
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