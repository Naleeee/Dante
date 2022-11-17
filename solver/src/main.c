/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "solver.h"
#include <stdlib.h>
#include "lib.h"

int main(int ac, char **av)
{
    char *my_map = NULL;

    if (ac != 2)
        return 84;
    if ((my_map = my_reader(av[1])) == NULL)
        return 84;
    return (solver(my_map));
}