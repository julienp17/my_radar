/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Handles command line arguments
*/

#include "usage.h"
#include "my.h"

int check_args(int ac, char **av)
{
    if (ac != 2) {
        print_bad_ac(ac, av);
        return (MY_EXIT_FAILURE);
    }
    if (check_options(av[1]) == MY_EXIT_SUCCESS)
        return (MY_EXIT_OPTION);
    return (MY_EXIT_SUCCESS);
}

int check_options(char *arg)
{
    if (my_strcmp(arg, "-h") == 0 || my_strcmp(arg, "--help") == 0) {
        print_help();
        return (MY_EXIT_SUCCESS);
    }
    return (MY_EXIT_FAILURE);
}

void print_help(void)
{
    my_putstr(SHORT_PROGRAM_DESCRIPTION);
    my_putchar('\n');
    my_putstr(USAGE);
    my_putchar('\n');
    my_putstr(OPTIONS);
    my_putchar('\n');
    my_putstr(USER_INTERACTIONS);
}

void print_bad_ac(int ac, char **av)
{
    my_puterr(av[0]);
    my_puterr(": bad arguments: ");
    my_puterr(my_int_to_strnum(ac - 1));
    my_puterr(" given but 1 is required\n");
    my_puterr("retry with -h\n");
}