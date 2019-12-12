/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for my_radar core functions
*/

#ifndef MY_RADAR_H_
    #define MY_RADAR_H_

    #include <SFML/Graphics.h>

    int launch_simulation(char const *file_path);
    void poll_events(sfRenderWindow *window, sfEvent *event);
#endif