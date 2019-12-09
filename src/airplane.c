/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Source file for airplane structure
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include "airplane.h"

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