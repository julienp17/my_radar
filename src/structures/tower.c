/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for control tower structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "tower.h"

tower_t *tower_create(sfVector2i pos, unsigned int radius)
{
    tower_t *tower = malloc(sizeof(*tower));

    tower->pos    = pos;
    tower->radius = radius;
    return (tower);
}