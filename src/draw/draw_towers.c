/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Draw towers
*/

#include <SFML/Graphics.h>
#include "tower.h"
#include "sim_states.h"

void draw_towers(sfRenderWindow *window, tower_t **towers, states_t *states)
{
    if (!(states->show_hitbox) && !(states->show_sprites))
        return;
    for (unsigned int i = 0 ; towers[i] ; i++) {
        if (states->show_sprites)
            sfRenderWindow_drawSprite(window, towers[i]->sprite, NULL);
        if (states->show_hitbox)
            sfRenderWindow_drawCircleShape(window,
                                        towers[i]->control_area, NULL);
    }
}