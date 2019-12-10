/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for control tower structure
*/

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include "tower.h"
#include "file_manipulation.h"
#include "my.h"

static tower_t *add_tower_from_line(char *current_line);
static unsigned int get_nb_towers_from_file(char const *file_path);

tower_t *tower_create(sfVector2i pos, unsigned int radius)
{
    tower_t *tower = malloc(sizeof(*tower));

    tower->pos    = pos;
    tower->radius = radius;
    return (tower);
}

tower_t **get_towers_from_file(char const *file_path)
{
    unsigned int nb_towers = get_nb_towers_from_file(file_path);
    tower_t **towers = malloc(sizeof(*towers) * (nb_towers + 1));
    FILE *stream = fopen(file_path, "r");
    char *current_line = NULL;
    long unsigned int size = 50;
    unsigned int i = 0;

    while (getline(&current_line, &size, stream) != -1) {
        if (current_line[0] == TOWER_SYMBOL) {
            current_line++;
            towers[i] = add_tower_from_line(current_line);
            i++;
        }
    }
    fclose(stream);
    return (towers);
}

static tower_t *add_tower_from_line(char *current_line)
{
    sfVector2i pos;
    unsigned int radius;

    pos.x  = strtol(current_line, &current_line, 10);
    pos.y  = strtol(current_line, &current_line, 10);
    radius = strtol(current_line, &current_line, 10);
    return (tower_create(pos, radius));
}

static unsigned int get_nb_towers_from_file(char const *file_path)
{
    return (my_count_char(get_file_buffer(file_path), TOWER_SYMBOL));
}
