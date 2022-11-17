/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "solver.h"
#include "lib.h"

Test(size_line, no_slashzero)
{
    char *map = "test";
    int res = size_line(map);

    cr_assert_eq(res, 4);
}

Test(test_end, basic)
{
    int res = test_end(2, 5, 2, 4);

    cr_assert_eq(res, 1);
}