/*
** EPITECH PROJECT, 2021
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "generator.h"
#include "lib.h"
#include <stdio.h>

Test(main_function, tenxten)
{
    char *av[] = {"./generator/generator", "10", "10"};
    int res = generator(3, av);

    cr_assert_eq(res, 0);
}

Test(main_function, not_en_args)
{
    char *av[] = {"./generator/generator", "10"};
    int res = generator(2, av);

    cr_assert_eq(res, 84);
}

Test(main_function, too_much_args)
{
    char *av[] = {"./generator/generator", "10", "10", "12", "13"};
    int res = generator(5, av);

    cr_assert_eq(res, 84);
}

Test(main_function, x_zero)
{
    char *av[] = {"./generator/generator", "0", "10"};
    int res = generator(3, av);

    cr_assert_eq(res, 84);
}

Test(main_function, y_zero)
{
    char *av[] = {"./generator/generator", "10", "0"};
    int res = generator(3, av);

    cr_assert_eq(res, 84);
}

Test(main_function, perfect)
{
    char *av[] = {"./generator/generator", "10", "10", "perfect"};
    int res = generator(4, av);

    cr_assert_eq(res, 0);
}

Test(main_function, too_much_tiles)
{
    char *av[] = {"./generator/generator", "1000", "1000"};
    int res = generator(3, av);

    cr_assert_eq(res, 0);
}