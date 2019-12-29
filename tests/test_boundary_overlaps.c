/*
** EPITECH PROJECT, 2019
** my_radar
** File description:
** Unit test for boundary_overlaps boolean function
*/

#include <SFML/Graphics.h>
#include <criterion/criterion.h>
#include "utils.h"

Test(test_boundary_overlaps, other_too_left)
{
    sfIntRect rect = {500, 500, 200, 200};
    sfIntRect other = {200, 500, 200, 200};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = boundary_overlaps(rect, other);
    cr_assert_eq(actual, expected);
}

Test(test_boundary_overlaps, other_too_right)
{
    sfIntRect rect = {500, 500, 200, 200};
    sfIntRect other = {800, 500, 200, 200};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = boundary_overlaps(rect, other);
    cr_assert_eq(actual, expected);
}

Test(test_boundary_overlaps, other_too_high)
{
    sfIntRect rect = {500, 500, 200, 200};
    sfIntRect other = {500, 200, 200, 200};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = boundary_overlaps(rect, other);
    cr_assert_eq(actual, expected);
}

Test(test_boundary_overlaps, other_too_low)
{
    sfIntRect rect = {500, 500, 200, 200};
    sfIntRect other = {500, 800, 200, 200};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = boundary_overlaps(rect, other);
    cr_assert_eq(actual, expected);
}

Test(test_boundary_overlaps, other_overlaps)
{
    sfIntRect rect = {500, 500, 200, 200};
    sfIntRect other = {400, 400, 200, 200};
    sfBool actual = sfFalse;
    sfBool expected = sfTrue;

    actual = boundary_overlaps(rect, other);
    cr_assert_eq(actual, expected);
}

Test(test_boundary_overlaps, other_one_pixel_on_the_left)
{
    sfIntRect rect = {500, 500, 200, 200};
    sfIntRect other = {299, 500, 200, 200};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = boundary_overlaps(rect, other);
    cr_assert_eq(actual, expected);
}

Test(test_boundary_overlaps, other_one_pixel_on_the_right)
{
    sfIntRect rect = {500, 500, 200, 200};
    sfIntRect other = {701, 500, 200, 200};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = boundary_overlaps(rect, other);
    cr_assert_eq(actual, expected);
}

Test(test_boundary_overlaps, other_one_pixel_on_the_top)
{
    sfIntRect rect = {500, 500, 200, 200};
    sfIntRect other = {500, 299, 200, 200};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = boundary_overlaps(rect, other);
    cr_assert_eq(actual, expected);
}

Test(test_boundary_overlaps, other_one_pixel_on_the_bottom)
{
    sfIntRect rect = {500, 500, 200, 200};
    sfIntRect other = {500, 701, 200, 200};
    sfBool actual = sfFalse;
    sfBool expected = sfFalse;

    actual = boundary_overlaps(rect, other);
    cr_assert_eq(actual, expected);
}