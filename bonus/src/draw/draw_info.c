/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Draws info about the info
*/

#include <SFML/Graphics.h>
#include "sim_info.h"
#include "sim_texts.h"
#include "sim_states.h"

void draw_info(sfRenderWindow *render,texts_t *texts, states_t *states)
{
    if (!(states->show_info))
        return;
    sfRenderWindow_drawText(render, texts->fps, NULL);
    sfRenderWindow_drawText(render, texts->nb_planes, NULL);
    sfRenderWindow_drawText(render, texts->nb_planes_flying, NULL);
    sfRenderWindow_drawText(render, texts->nb_towers, NULL);
}