/*
** EPITECH PROJECT, 2021
** solver
** File description:
** solver
*/

#include "solver.h"
#include "lib.h"

int test_end(int x, int y, int e_x, int e_y)
{
    if (e_x == x && e_y == y) {
        return 0;
    }
    return 1;
}

char **recursif(end_t end, char **map, int x, int y)
{
    char **tmp = NULL;

    map[y][x] = 'o';
    if (test_end(x, y, end.x, end.y) == 0)
        return map;
    if (x + 1 <= end.x && map[y][x + 1] == '*')
        if ((tmp = recursif(end, map, x + 1, y)) != NULL)
            return tmp;
    if (y + 1 <= end.y && map[y + 1][x] == '*')
        if ((tmp = recursif(end, map, x, y + 1)) != NULL)
            return tmp;
    if (x - 1 >= 0 && map[y][x - 1] == '*')
        if ((tmp = recursif(end, map, x - 1, y)) != NULL)
            return tmp;
    if (y - 1 >= 0 && map[y - 1][x] == '*')
        if ((tmp = recursif(end, map, x, y - 1)) != NULL)
            return tmp;
    map[y][x] = '*';
    return NULL;
}

int solver(char *s_map)
{
    char **map = NULL;
    end_t end;

    end.y = size_map(s_map) - 1;
    end.x = size_line(s_map) - 1;
    map = set_map(s_map);
    if (map[0][0] != '*' || map[end.y][end.x] != '*')
        return 84;
    map = recursif(end, map, 0, 0);
    if (map == NULL) {
        printf("no solution found\n");
        return 0;
    }
    my_show_word_array(map);
    return 0;
}
