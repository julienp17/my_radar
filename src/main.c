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
    sim_t *sim = NULL;
    int error_code = 0;

    error_code = check_args(ac, av);
    if (error_code == MY_EXIT_OPTION)
        return (MY_EXIT_SUCCESS);
    else if (error_code == MY_EXIT_FAILURE)
        return (error_code);
    srand(time(NULL));
    sim = sim_create_from_script(av[1]);
    if (!sim) {
        my_puterr("Simulation couldn't be created.\n");
        return (MY_EXIT_FAILURE);
    }
    launch_simulation(sim);
    sim_destroy(sim);
    return (error_code);
}