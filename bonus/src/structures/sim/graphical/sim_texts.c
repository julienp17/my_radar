/*
** EPITECH PROJECT, 2020
** my_radar
** File description:
** Source file for structure sim_texts
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "sim_texts.h"
#include "sim_fonts.h"
#include "sim_info.h"
#include "window.h"
#include "my.h"

static text_t *init_timer_text(font_t *font, window_t *window);
static text_t *get_info_text(window_t *window, unsigned int y_offset,
                            font_t *font);

sim_texts_t *sim_texts_create(window_t *window, fonts_t *fonts)
{
    sim_texts_t *texts = malloc(sizeof(sim_texts_t));

    if (!texts)
        return (NULL);
    texts->timer = init_timer_text(fonts->skyfont, window);
    texts->nb_planes = get_info_text(window, 100, fonts->falling_sky);
    texts->nb_towers = get_info_text(window, 70, fonts->falling_sky);
    if (!(texts->timer))
        return (NULL);
    return (texts);
}

void sim_texts_destroy(sim_texts_t *texts)
{
    sfText_destroy(texts->timer);
    sfText_destroy(texts->nb_planes);
    sfText_destroy(texts->nb_towers);
    if (texts)
        free(texts);
}

static text_t *init_timer_text(font_t *font, window_t *window)
{
    sfText *timer_text = sfText_create();
    sfVector2f pos = {window->width - 250, 0};

    sfText_setCharacterSize(timer_text, 100);
    sfText_setFont(timer_text, font);
    sfText_setColor(timer_text, sfBlack);
    sfText_setPosition(timer_text, pos);
    return (timer_text);
}

static text_t *get_info_text(window_t *window,
                            unsigned int y_offset, font_t *font)
{
    sfText *text = sfText_create();
    sfVector2f pos = {window->width / 2, window->height - y_offset};

    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, pos);
    return (text);
}