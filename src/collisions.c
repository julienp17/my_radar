/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Handles the collisions for my_radar
*/

#include <SFML/Graphics.h>
#include "sim.h"
#include "collisions.h"
#include "utils.h"

plane_t *get_collided_plane(plane_t *plane, tower_t **towers,
                            quadtree_t *quadtree)
{
    if (plane_is_in_control_area(plane->hitbox, towers)) {
        sfRectangleShape_setOutlineColor(plane->outline, sfGreen);
        return (sfFalse);
    } else {
        sfRectangleShape_setOutlineColor(plane->outline, sfYellow);
    }
    return (plane_check_collisions(plane, quadtree));
}

sfBool plane_is_in_control_area(sfFloatRect hitbox, tower_t **towers)
{
    for (unsigned int i = 0 ; towers[i] ; i++)
        if (boundary_is_in_circle(hitbox, towers[i]->pos, towers[i]->radius))
            return (sfTrue);
    return (sfFalse);
}

plane_t *plane_check_collisions(plane_t *plane, quadtree_t *quadtree)
{
    sfIntRect area = (sfIntRect) {plane->path->pos.x - 30.0,
                                plane->path->pos.y - 30.0, 50, 50};
    plane_t **planes = quadtree_query(quadtree, area);

    if (!planes)
        return (NULL);
    for (unsigned int i = 0 ; planes[i] ; i++)
        if (!(pos_match(plane->path->pos, planes[i]->path->pos)))
            return (planes[i]);
    return (NULL);
}