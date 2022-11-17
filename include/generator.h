/*
** EPITECH PROJECT, 2021
** gene
** File description:
** gene
*/

#ifndef gene
#define gene

#define MAP     main->map

typedef enum direction
{
    up,
    right,
    down,
    left
} direction;

typedef struct main
{
    int x;
    int y;
    int perfect;
    char **map;
} main_t;

int dig(main_t *main, int x, int y, direction prev);
direction *get_random(main_t *main, int x, int y, direction prev);
int generator(int ac, char **av);
int parse_args(int ac, char *av[], main_t *main);

#endif /* !gene */