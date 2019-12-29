/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Unit tests for pos_match boolean function
*/

#include <SFML/Graphics.h>
#include <criterion/criterion.h>
#include "utils.h"

Test(test_pos_are_near, not_near)
{
    sfVector2f pos_1 = {10.0, 10.0};
    sfVector2f pos_2 = {20.0, 20.0};
    float const threshold = 5.0;
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = pos_are_near(pos_1, pos_2, threshold);
    cr_assert_eq(actual, expected);
}

Test(test_pos_are_near, near_on_threshold)
{
    sfVector2f pos_1 = {10.0, 10.0};
    sfVector2f pos_2 = {20.0, 20.0};
    float const threshold = 10.0;
    sfBool actual = sfFalse;
    sfBool expected = sfTrue;

    actual = pos_are_near(pos_1, pos_2, threshold);
    cr_assert_eq(actual, expected);
}

Test(test_pos_are_near, near_in_threshold)
{
    sfVector2f pos_1 = {10.0, 10.0};
    sfVector2f pos_2 = {20.0, 20.0};
    float const threshold = 15.0;
    sfBool actual = sfFalse;
    sfBool expected = sfTrue;

    actual = pos_are_near(pos_1, pos_2, threshold);
    cr_assert_eq(actual, expected);
}