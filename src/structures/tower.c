/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for control tower structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "tower.h"

tower_t *tower_create(sfVector2f pos, sfTexture *texture, unsigned int radius)
{
    tower_t *tower = malloc(sizeof(*tower));
    sfVector2f circle_pos = {pos.x + 20 - radius, pos.y + 20 - radius};

    if (!tower)
        return (NULL);
    tower->pos          = pos;
    tower->sprite       = sfSprite_create();
    tower->control_area = sfCircleShape_create();
    sfSprite_setTexture(tower->sprite, texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->pos);
    sfCircleShape_setRadius(tower->control_area, radius);
    sfCircleShape_setFillColor(tower->control_area, sfTransparent);
    sfCircleShape_setOutlineColor(tower->control_area, sfBlue);
    sfCircleShape_setOutlineThickness(tower->control_area, radius / 25);
    sfCircleShape_setPosition(tower->control_area, circle_pos);
    return (tower);
}

void tower_destroy(tower_t *tower)
{
    sfSprite_destroy(tower->sprite);
    sfCircleShape_destroy(tower->control_area);
    free(tower);
}

sfVector2f get_random_tower_pos(tower_t **towers)
{
    unsigned int nb_towers = 0;
    sfVector2f random_tower_pos;

    for (nb_towers = 0 ; towers[nb_towers] ; nb_towers++);
    random_tower_pos = (towers[rand() % nb_towers])->pos;
    return (random_tower_pos);
}

sfBool vector2f_match(sfVector2f pos_1, sfVector2f pos_2)
{
    return (pos_1.x == pos_2.x && pos_1.y == pos_2.x);
}