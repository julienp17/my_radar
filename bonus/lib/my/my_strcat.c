/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** my_strcat
*/

char *my_strcat(char *dest, char const *src)
{
    unsigned int i = 0;
    unsigned int j = 0;

    while (dest[i])
        i++;
    while (src[j]) {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}