/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Returns the number of times a given char appears in a given string
*/

unsigned int my_count_char(char const *str, char const to_count)
{
    unsigned int count = 0;

    for (unsigned int i = 0 ; str[i] ; i++)
        if (str[i] == to_count)
            count++;
    return (count);
}