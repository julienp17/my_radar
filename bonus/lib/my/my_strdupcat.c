/*
** EPITECH PROJECT, 2020
** PSU_my_ls_2019
** File description:
** my_strdupcat
*/

#include <stdlib.h>

unsigned int my_strlen(char const *str);

char *my_strdupcat(char const *s1, char const *s2)
{
    char *str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    unsigned int i = 0;

    for (i = 0 ; s1[i] ; i++)
        str[i] = s1[i];
    for (unsigned int j = 0 ; s2[j] ; i++, j++)
        str[i] = s2[j];
    str[i] = '\0';
    return (str);
}