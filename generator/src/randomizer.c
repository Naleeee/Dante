/*
** EPITECH PROJECT, 2021
** randomizer
** File description:
** randomizer
*/

#include "generator.h"
#include <stdlib.h>

direction *get_random(main_t *main, int x, int y, direction prev)
{
    direction *res = malloc(sizeof(direction) * 4);
    int check[4] = {down, left, up, right};
    int test;

    if (res == NULL)
        return NULL;
    check[prev] = -1;
    for (int i = 0; i < 3; i++) {
        test = rand() % 4;
        if (check[test] != -1) {
            res[i] = check[test];
            check[test] = -1;
        } else
            i--;
    }
    if (y == main->y - 1 && (x + 1 == main->x - 1 || x + 2 == main->x - 1 ))
        res[0] = right;
    if (x == main->x - 1 && (y + 1 == main->y - 1 || y + 2 == main->y - 1 ))
        res[0] = down;
    return res;
}