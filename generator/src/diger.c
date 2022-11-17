/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** diger
*/

#include <stdlib.h>
#include <stdio.h>
#include "generator.h"

int check_tile(main_t *main, int x, int y)
{
    int test = 0;

    if (y - 1 >= 0 && MAP[y - 1][x] == '*')
        test++;
    if (x + 1 <= main->x - 1 && MAP[y][x + 1] == '*')
        test++;
    if (y + 1 <= main->y - 1 && MAP[y + 1][x] == '*')
        test++;
    if (x - 1 >= 0 && MAP[y][x - 1] == '*')
        test++;
    if (test > 1)
        return 0;
    return 1;
}

static int choose_direction(main_t *main, int x, int y, direction direction)
{
    switch (direction) {
    case up:
        if (y - 1 >= 0)
            return dig(main, x, y - 1, up);
        break;
    case right:
        if (x + 1 <= main->x - 1)
            return dig(main, x + 1, y, right);
        break;
    case left:
        if (x - 1 >= 0)
            return dig(main, x - 1, y, left);
        break;
    case down:
        if (y + 1 <= main->y - 1)
            return dig(main, x, y + 1, down);
    }
    return 0;
}

int dig(main_t *main, int x, int y, direction prev)
{
    direction *directions;

    if (!check_tile(main, x, y))
        return 0;
    MAP[y][x] = '*';
    if (y == main->y - 1 && x == main->x - 1)
        return 0;
    directions = get_random(main, x, y, prev);
    for (size_t i = 0; i < 3; i++)
        choose_direction(main, x, y, directions[i]);
    free(directions);
    return 0;
}