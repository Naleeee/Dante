/*
** EPITECH PROJECT, 2021
** Dente
** File description:
** generator
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include "generator.h"

int parse_args(int ac, char *av[], main_t *main)
{
    if (ac < 3 || ac > 4) {
        write(2, "Invalid number of args\n", 23);
        return 84;
    }
    main->x = atoi(av[1]);
    main->y = atoi(av[2]);
    if (main->x <= 0 || main->y <= 0) {
        write(2, "Invalid size\n", 13);
        return 84;
    }
    main->perfect = 0;
    if (ac == 4)
        main->perfect = 1;
    return 0;
}

char **init_map(int max_x, int max_y)
{
    char **map = malloc(sizeof(char *) * (max_y + 1));

    for (int y = 0; y < max_y; y++) {
        map[y] = malloc(sizeof(char) * (max_x + 2));
        for (int x = 0; x < max_x; x++) {
            map[y][x] = 'X';
        }
        map[y][max_x] = '\n';
        map[y][max_x + 1] = '\0';
        if (y == max_y - 1)
            map[y][max_x] = '\0';
    }
    map[max_y] = NULL;
    map[0][0] = '*';
    return map;
}

void break_maze(main_t *main)
{
    int x;
    int y;

    for (int i = 0; i < main->x / 2; i++) {
        x = rand() % main->x;
        y = rand() % main->y;
        if (MAP[y][x] == 'X')
            MAP[y][x] = '*';
        else
            i--;
    }
}

int generator(int ac, char **av)
{
    main_t main;

    srand(time(NULL));
    if (parse_args(ac, av, &main) == 84)
        return 84;
    if (main.x * main.y > 450000) {
        write(2, "Generator cannot handle to big maze size\n", 41);
        write(2, "Maximum is 450000 tiles\n", 24);
        return 0;
    }
    main.map = init_map(main.x, main.y);
    dig(&main, 0, 0, right);
    if (main.perfect == 0)
        break_maze(&main);
    for (int i = 0; i < main.y; i++)
        printf("%s", main.map[i]);
    for (int i = 0; i < main.y; i++)
        free(main.map[i]);
    free(main.map);
    return 0;
}