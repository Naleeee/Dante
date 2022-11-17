/*
** EPITECH PROJECT, 2021
** map
** File description:
** map
*/

#include <string.h>
#include "solver.h"

int size_line(char *map)
{
    int i = 0;

    while (map[i] != '\0') {
        if (map[i] == '\n')
            return i;
        i++;
    }
    return i;
}

int size_map(char *map)
{
    int nb = 1;

    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == '\n') {
            nb++;
        }
    }
    return nb;
}

char **set_map(char *map)
{
    int size = size_map(map);
    char **f_map = malloc(sizeof(char *) * (size + 1));

    f_map[0] = strtok(map, "\n");
    for (int i = 1; i < size; i++)
        f_map[i] = strtok(NULL, "\n");
    f_map[size] = NULL;
    return f_map;
}