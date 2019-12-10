/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Print a string to standard output.
*/

#include <unistd.h>

void my_putstr(char const *str)
{
    for (unsigned int i = 0 ; str[i] ; i++)
        write(1, &(str[i]), 1);
}