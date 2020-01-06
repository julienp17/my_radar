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
#include "events.h"
#include "sim.h"
#include "my.h"

int main(int ac, char **av)
{
    window_t *window = NULL;
    int exit_code = 0;

    exit_code = check_args(ac, av);
    if (exit_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (exit_code == MY_EXIT_FAILURE)
        return (exit_code);
    srand(time(NULL));
    if ((window = window_create(W_WIDTH, W_HEIGHT, W_TITLE)) == NULL) {
        my_puterr("my_radar: Couldn't create window\n");
        return (MY_EXIT_FAILURE);
    }
    exit_code = launch_simulation(window, av[1]);
    return (MY_EXIT_SUCCESS);
}