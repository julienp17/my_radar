/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for path structure
*/

#ifndef PATH_H_
    #define PATH_H_

    #include <SFML/Graphics.h>

    typedef struct path {
        sfVector2f pos;
        sfVector2f end;
        sfVector2f step;
    } path_t;

    path_t *path_create(sfVector2f beg, sfVector2f end, unsigned int speed);
    sfVector2f get_step_offset(sfVector2f point_a, sfVector2f point_b);
#endif