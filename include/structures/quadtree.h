/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for quadtree structure
*/

#ifndef QUADTREE_H_
    #define QUADTREE_H_

    #include <SFML/Graphics.h>
    #include "plane.h"

    #define QT_CAPACITY      4

    typedef struct quadtree {
        sfIntRect boundary;
        plane_t **planes;
        unsigned int nb_planes;
        struct quadtree **children;
        sfBool is_divided;
    } quadtree_t;

    quadtree_t *quadtree_create(sfIntRect boundary);
    int quadtree_insert(quadtree_t *quadtree, plane_t *plane);
    int quadtree_subdivide(quadtree_t **quadtree);
#endif