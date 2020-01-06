/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for quadtree_query
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "quadtree.h"
#include "utils.h"

static void quadtree_query_recursively(quadtree_t *quadtree, plane_t **planes,
                            unsigned int *plane_index, sfIntRect const area);

plane_t **quadtree_query(quadtree_t *quadtree, sfIntRect const area)
{
    unsigned int nb_planes = quadtree_get_nb_planes_in_area(quadtree, area);
    plane_t **planes = malloc(sizeof(plane_t *) * (nb_planes) + 1);
    unsigned int plane_index = 0;

    if (!planes)
        return (NULL);
    quadtree_query_recursively(quadtree, planes, &plane_index, area);
    planes[plane_index] = NULL;
    return (planes);
}

static void quadtree_query_recursively(quadtree_t *quadtree, plane_t **planes,
                            unsigned int *plane_index, sfIntRect const area)
{
    if (!(boundary_overlaps(quadtree->boundary, area)))
        return;
    if (quadtree->is_divided)
        for (unsigned int i = 0 ; i < 4 ; i++)
            quadtree_query_recursively(quadtree->children[i], planes,
                                        plane_index, area);
    for (unsigned int i = 0 ; quadtree->planes[i] ; i++)
        if (boundary_contains_pos(area, quadtree->planes[i]->path->pos)) {
            planes[*(plane_index)] = quadtree->planes[i];
            (*plane_index) += 1;
        }
}

unsigned int quadtree_get_nb_planes_in_area(quadtree_t *quadtree,
                                            sfIntRect const area)
{
    unsigned int nb_planes = 0;

    if (!(boundary_overlaps(quadtree->boundary, area)))
        return (0);
    if (quadtree->is_divided)
        for (unsigned int i = 0 ; i < 4 ; i++)
            nb_planes += quadtree_get_nb_planes_in_area(quadtree->children[i],
                                                        area);
    for (unsigned int i = 0 ; quadtree->planes[i] ; i++)
        if (boundary_contains_pos(area, quadtree->planes[i]->path->pos))
            nb_planes++;
    return (nb_planes);
}