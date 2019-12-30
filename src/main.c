/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Main file for my_radar
*/

#include <stdlib.h>
#include <time.h>
#include "my_radar.h"
#include "usage.h"
#include "start_menu.h"

int main(int ac, char **av)
{
    int exit_code = 0;

    exit_code = check_args(ac, av);
    if (exit_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (exit_code == MY_EXIT_FAILURE)
        return (exit_code);
    srand(time(NULL));
    exit_code = start_menu();
    if (exit_code == 1)
        exit_code = my_radar(av[1]);
    return (exit_code);
}