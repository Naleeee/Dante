/*
** EPITECH PROJECT, 2021
** solver
** File description:
** solver
*/

#ifndef solver_h
#define solver_h

#include <stdio.h>
#include <stdlib.h>

typedef struct end_s {
    int x;
    int y;
}end_t;

int solver(char *map);
int move_one(char **map, int *x, int *y);
int size_map(char *map);
int size_line(char *map);
char **set_map(char *map);
int test_end(int x, int y, int e_x, int e_y);

#endif /* !solver */
