/*
** EPITECH PROJECT, 2020
** my_show_in_array
** File description:
** test
*/

#include <stddef.h>

void my_putchar(char c);

int my_putstr(char const *str);

int my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        if (tab[i + 1] != NULL)
            my_putchar('\n');
    }
    return 0;
}