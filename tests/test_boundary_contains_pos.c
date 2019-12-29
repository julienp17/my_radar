/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Unit tests for pos_match boolean function
*/

#include <SFML/Graphics.h>
#include <criterion/criterion.h>
#include "utils.h"

Test(test_boundary_contains_pos, no_contain)
{
    sfIntRect boundary = {0, 0, 500, 500};
    sfVector2f pos = {650, 700};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = boundary_contains_pos(boundary, pos);
    cr_assert_eq(actual, expected);
}

Test(test_boundary_contains_pos, contains)
{
    sfIntRect boundary = {0, 0, 500, 500};
    sfVector2f pos = {450, 300};
    sfBool actual = sfFalse;
    sfBool expected = sfTrue;

    actual = boundary_contains_pos(boundary, pos);
    cr_assert_eq(actual, expected);
}