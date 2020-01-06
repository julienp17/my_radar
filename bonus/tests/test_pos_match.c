/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Unit tests for pos_match boolean function
*/

#include <SFML/Graphics.h>
#include <criterion/criterion.h>
#include "utils.h"

Test(test_pos_match, no_match)
{
    sfVector2f pos_1 = {4.0, 2.0};
    sfVector2f pos_2 = {3.6, 8.9};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = pos_match(pos_1, pos_2);
    cr_assert_eq(actual, expected);
}

Test(test_pos_match, match)
{
    sfVector2f pos_1 = {4.0, 4.0};
    sfVector2f pos_2 = {4.0, 4.0};
    sfBool actual = sfFalse;
    sfBool expected = sfTrue;

    actual = pos_match(pos_1, pos_2);
    cr_assert_eq(actual, expected);
}