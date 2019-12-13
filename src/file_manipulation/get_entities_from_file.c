/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Fill the planes and towers from a script file
*/

#include <stdio.h>
#include <stdlib.h>
#include "file_manipulation.h"
#include "plane.h"
#include "tower.h"
#include "my.h"

int get_entities_from_file(char const *file_path, plane_t ***planes,
                            tower_t ***towers)
{
    unsigned int nb_planes = get_nb_entities_from_file(file_path, PLANE_SYMBOL);
    unsigned int nb_towers = get_nb_entities_from_file(file_path, TOWER_SYMBOL);
    FILE *stream = fopen(file_path, "r");

    (*planes) = malloc(sizeof(*planes) * (nb_planes + 1));
    (*towers) = malloc(sizeof(*towers) * (nb_towers + 1));
    if (fill_entities_by_line(stream, planes, towers) == -1)
        return (-1);
    fclose(stream);
    return (0);
}

unsigned int get_nb_entities_from_file(char const *file_path, char const symbol)
{
    char *file_buffer = get_file_buffer(file_path);

    return (my_count_char(file_buffer, symbol));
}

int fill_entities_by_line(FILE *stream, plane_t ***planes, tower_t ***towers)
{
    char *current_line = NULL;
    long unsigned int size = 50;
    unsigned int plane_index = 0;
    unsigned int tower_index = 0;

    while (getline(&current_line, &size, stream) != -1) {
        if (current_line[0] == PLANE_SYMBOL) {
            current_line++;
            (*planes)[plane_index] = add_plane_from_line(current_line);
            plane_index++;
        } else if (current_line[0] == TOWER_SYMBOL) {
            current_line++;
            (*towers)[tower_index] = add_tower_from_line(current_line);
            tower_index++;
        } else {
            return (-1);
        }
    }
    (*planes)[plane_index] = NULL;
    (*towers)[tower_index] = NULL;
    return (0);
}

plane_t *add_plane_from_line(char *current_line)
{
    sfVector2f departure;
    sfVector2f arrival;
    unsigned int speed = 0;
    unsigned int delay = 0;

    departure.x = my_strtol(current_line, &current_line);
    departure.y = my_strtol(current_line, &current_line);
    arrival.x   = my_strtol(current_line, &current_line);
    arrival.y   = my_strtol(current_line, &current_line);
    speed       = my_strtol(current_line, &current_line);
    delay       = my_strtol(current_line, &current_line);
    return (plane_create(departure, arrival, speed, delay));
}

tower_t *add_tower_from_line(char *current_line)
{
    sfVector2f pos;
    unsigned int radius = 0;

    pos.x  = my_strtol(current_line, &current_line);
    pos.y  = my_strtol(current_line, &current_line);
    radius = my_strtol(current_line, &current_line);
    return (tower_create(pos, radius));
}