/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Header file for usage
*/

#ifndef USAGE_H_
    #define USAGE_H_

    #define MY_EXIT_SUCCESS         0
    #define MY_EXIT_OPTION          192
    #define MY_EXIT_FAILURE         84

    #define SHORT_PROGRAM_DESCRIPTION                                          \
    "Air traffic simulation panel\n"
    #define USAGE                                                              \
    "USAGE\n"                                                                  \
    "  ./my_radar [OPTIONS] path_to_script\n"                                  \
    "    path_to_script    The path to the script file.\n"
    #define OPTIONS                                                            \
    "OPTIONS\n"                                                                \
    " -h | --help          print the usage and quit.\n"
    #define USER_INTERACTIONS                                                  \
    "USER INTERACTIONS\n"                                                      \
    " 'L' key              enable/disable hitboxes and areas.\n"               \
    " 'S' key              enable/disable sprites.\n"

    int check_args(int ac, char **av);
    int check_options(char *arg);
    void print_help(void);
    void print_bad_ac(int ac, char **av);
#endif