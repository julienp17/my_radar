/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for quadtree structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "quadtree.h"
#include "utils.h"

quadtree_t *quadtree_create(sfIntRect boundary)
{
    quadtree_t *quadtree = malloc(sizeof(*quadtree));

    if (!quadtree)
        return (NULL);
    quadtree->boundary = boundary;
    quadtree->children = NULL;
    quadtree->is_divided = sfFalse;
    quadtree->nb_planes = 0;
    quadtree->planes = malloc(sizeof(plane_t *) * (QT_CAPACITY + 1));
    if (!(quadtree->planes))
        return (NULL);
    for (unsigned int i = 0 ; i <= QT_CAPACITY ; i++)
        quadtree->planes[i] = NULL;
    return (quadtree);
}

void quadtree_clear(quadtree_t *quadtree)
{
    if (quadtree->is_divided) {
        for (unsigned int i = 0 ; quadtree->children[i] ; i++) {
            quadtree_clear(quadtree->children[i]);
            free(quadtree->children[i]);
        }
        quadtree->is_divided = sfFalse;
    }
    for (unsigned int i = 0 ; quadtree->planes[i] ; i++)
        quadtree->planes[i] = NULL;
    quadtree->nb_planes = 0;
}

int quadtree_insert(quadtree_t *quadtree, plane_t *plane)
{
    if (!(boundary_contains_pos(quadtree->boundary, plane->path->pos)))
        return (1);
    if (quadtree->nb_planes < QT_CAPACITY && !(quadtree->is_divided)) {
        quadtree->planes[quadtree->nb_planes] = plane;
        quadtree->nb_planes++;
        return (0);
    }
    if (!(quadtree->is_divided)) {
        if (quadtree_subdivide(&quadtree) != 0)
            return (-1);
        for (unsigned int i = 0 ; i < QT_CAPACITY ; i++) {
            quadtree_insert(quadtree, quadtree->planes[i]);
            quadtree->planes[i] = NULL;
        }
    }
    for (unsigned int i = 0 ; i < 4 ; i++)
        if (quadtree_insert(quadtree->children[i], plane) == 0) {
            quadtree->nb_planes++;
            return (0);
        }
    return (1);
}

int quadtree_subdivide(quadtree_t **quadtree)
{
    int x = (*quadtree)->boundary.left;
    int y = (*quadtree)->boundary.top;
    int w = (*quadtree)->boundary.width;
    int h = (*quadtree)->boundary.height;

    (*quadtree)->children = malloc(sizeof(quadtree_t *) * (4 + 1));
    if (!((*quadtree)->children))
        return (1);
    (*quadtree)->children[0] = quadtree_create((sfIntRect){x, y, w / 2, h / 2});
    (*quadtree)->children[1] = quadtree_create((sfIntRect){x + w / 2, y,
                                                w / 2, h / 2});
    (*quadtree)->children[2] = quadtree_create((sfIntRect){x, y + h / 2,
                                                w / 2, h / 2});
    (*quadtree)->children[3] = quadtree_create((sfIntRect){x + w / 2, y + h / 2,
                                                w / 2, h / 2});
    (*quadtree)->children[4] = NULL;
    for (unsigned int i = 0 ; i < 4 ; i++)
        if ((*quadtree)->children[i] == NULL)
            return (1);
    (*quadtree)->is_divided = sfTrue;
    return (0);
}