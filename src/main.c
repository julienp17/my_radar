/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Main file for my_radar
*/

#include "usage.h"

int launch_simulation(char const *file_path);

int main(int ac, char **av)
{
    int error_code = 0;

    error_code = check_args(ac, av);
    if (error_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (error_code == MY_EXIT_FAILURE)
        return (error_code);
    error_code = launch_simulation(av[1]);
    return (error_code);
}