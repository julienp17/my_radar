/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** Header file for file manipulation
*/

#ifndef FILE_MANIPULATION_H_
    #define FILE_MANIPULATION_H_

    #define OPEN_FAILURE_MSG        "File cannot be opened\n"
    #define READ_FAILURE_MSG        "File cannot be read\n"

    char *get_file_buffer(char const *filepath);
    unsigned int get_file_size(char const *filepath);
#endif