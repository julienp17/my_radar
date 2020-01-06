/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for drawing the quadtree
*/

#include <SFML/Graphics.h>
#include "quadtree.h"
#include "sim_states.h"

static void draw_quadtree_recursively(sfRenderWindow *window,
                            quadtree_t *quadtree, sfRectangleShape *boundary);

void draw_quadtree(sfRenderWindow *window, quadtree_t *quadtree,states_t *state)
{
    sfRectangleShape *boundary = NULL;

    if (!(state->show_quadtree))
        return;
    boundary = sfRectangleShape_create();
    sfRectangleShape_setFillColor(boundary, sfTransparent);
    sfRectangleShape_setOutlineColor(boundary, sfWhite);
    sfRectangleShape_setOutlineThickness(boundary, 2.0);
    draw_quadtree_recursively(window, quadtree, boundary);
    sfRectangleShape_destroy(boundary);
}

static void draw_quadtree_recursively(sfRenderWindow *window,
                            quadtree_t *quadtree, sfRectangleShape *boundary)
{
    sfVector2f boundary_pos  = {quadtree->boundary.left,
                                quadtree->boundary.top};
    sfVector2f boundary_size = {quadtree->boundary.width,
                                quadtree->boundary.height};

    sfRectangleShape_setPosition(boundary, boundary_pos);
    sfRectangleShape_setSize(boundary, boundary_size);
    sfRenderWindow_drawRectangleShape(window, boundary, NULL);
    if (quadtree->is_divided)
        for (unsigned int i = 0 ; i < 4 ; i++)
            draw_quadtree_recursively(window, quadtree->children[i], boundary);
}