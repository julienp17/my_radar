/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for file manipulation
*/

#ifndef FILE_MANIPULATION_H_
    #define FILE_MANIPULATION_H_

    #include "plane.h"
    #include "tower.h"

    #define OPEN_FAILURE_MSG        "File cannot be opened\n"
    #define READ_FAILURE_MSG        "File cannot be read\n"

    #define TOWER_TEXTURE_PATH      "assets/textures/tower_small.png"

    char *get_file_buffer(char const *file_path);
    unsigned int get_file_size(char const *file_path);

    int get_entities_from_file(char const *file_path, plane_t ***, tower_t ***);
    unsigned int get_nb_entities_from_file(char const *file_path,
                                            char const symbol);
    int fill_entities_by_line(FILE *stream, plane_t ***, tower_t ***);
    plane_t *add_plane_from_line(char *current_line);
    tower_t *add_tower_from_line(char *current_line);
#endif