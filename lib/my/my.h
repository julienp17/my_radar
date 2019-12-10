/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for libmy
*/

#ifndef MY_H_
    #define MY_H_

    void my_putchar(char c);
    void my_putstr(char const *str);
    void my_puterr(char const *str);

    int my_strcmp(char const *s1, char const *s2);
    unsigned int my_count_char(char const *str, char const to_count);
    unsigned int my_intlen(int nb);

    char *my_int_to_strnum(int nb);
    char *my_revstr(char *str);
#endif