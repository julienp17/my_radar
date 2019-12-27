/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for file manipulation
*/

#ifndef FILE_MANIPULATION_H_
    #define FILE_MANIPULATION_H_

    #include <stdio.h>
    #include <SFML/Graphics.h>
    #include "sim.h"
    #include "plane.h"
    #include "tower.h"

    #define OPEN_FAILURE_MSG        "File cannot be opened\n"
    #define READ_FAILURE_MSG        "File cannot be read\n"

    char *get_file_buffer(char const *file_path);
    unsigned int get_file_size(char const *file_path);

    int get_entities_from_file(char const *file_path, sim_t *sim);
    int fill_entities_by_line(FILE *stream, sim_t *sim);
    plane_t *add_plane_from_line(char *current_line, sfTexture *);
    tower_t *add_tower_from_line(char *current_line, sfTexture *);
#endif