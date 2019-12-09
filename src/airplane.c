/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for airplane structure
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <SFML/Graphics.h>
#include "airplane.h"
#include "file_manipulation.h"
#include "my.h"

static plane_t *add_plane_from_line(char *current_line);
static unsigned int get_nb_planes_from_file(char const *file_path);

plane_t **get_planes_from_file(char const *file_path)
{
    unsigned int nb_planes = get_nb_planes_from_file(file_path);
    plane_t **planes = malloc(sizeof(*planes) * (nb_planes + 1));
    FILE *stream = fopen(file_path, "r");
    char *current_line = NULL;
    long unsigned int size = 50;
    unsigned int i = 0;

    while (getline(&current_line, &size, stream) != -1) {
        if (current_line[0] == AIRPLANE_SYMBOL) {
            current_line++;
            planes[i] = add_plane_from_line(current_line);
            i++;
        }
    }
    fclose(stream);
    return (planes);
}

static plane_t *add_plane_from_line(char *current_line)
{
    sfVector2i departure;
    sfVector2i arrival;
    unsigned int speed;
    unsigned int delay;

    departure.x = strtol(current_line, &current_line, 10);
    departure.y = strtol(current_line, &current_line, 10);
    arrival.x   = strtol(current_line, &current_line, 10);
    arrival.y   = strtol(current_line, &current_line, 10);
    speed       = strtol(current_line, &current_line, 10);
    delay       = strtol(current_line, &current_line, 10);
    return (plane_create(departure, arrival, speed, delay));
}

static unsigned int get_nb_planes_from_file(char const *file_path)
{
    return (my_count_char(get_file_buffer(file_path), AIRPLANE_SYMBOL));
}

plane_t *plane_create(sfVector2i departure, sfVector2i arrival,
                    unsigned int speed, unsigned int delay)
{
    plane_t *plane = malloc(sizeof(*plane));

    plane->departure = departure;
    plane->arrival   = arrival;
    plane->speed     = speed;
    plane->delay     = delay;
    return (plane);
}