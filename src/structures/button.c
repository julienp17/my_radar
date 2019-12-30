/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for button structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "button.h"
#include "my.h"

static button_t *button_init(button_t *button, char *text,
                            sfVector2f pos, sfVector2f size);

button_t *button_create(char *text, char const *font_path,
                        sfVector2f pos, sfVector2f size)
{
    button_t *button = malloc(sizeof(button_t));
    sfColor button_fill_color = (sfColor) {156, 156, 156, 125};

    if (!button)
        return (NULL);
    button->rect = sfRectangleShape_create();
    button->text = sfText_create();
    button->font = sfFont_createFromFile(font_path);
    if (!(button->text) || !(button->rect) || !(button->font))
        return (NULL);
    sfText_setFont(button->text, button->font);
    sfText_setColor(button->text, sfWhite);
    sfRectangleShape_setFillColor(button->rect, button_fill_color);
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfRectangleShape_setOutlineThickness(button->rect, 2.0);
    return (button_init(button, text, pos, size));
}

static button_t *button_init(button_t *button, char *text,
                            sfVector2f pos, sfVector2f size)
{
    unsigned int text_size = size.x / 15;
    sfVector2f text_pos = (sfVector2f) {
        (pos.x + size.x / 2) - text_size * 6,
        (pos.y + size.y / 2) - text_size,
    };

    sfText_setString(button->text, text);
    sfText_setPosition(button->text, text_pos);
    sfText_setCharacterSize(button->text, text_size);
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setSize(button->rect, size);
    return (button);
}

void button_destroy(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    sfText_destroy(button->text);
    sfFont_destroy(button->font);
    if (button)
        free(button);
}