/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** display every characters of a char string
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int a = 0;
    int b = str[0];

    while (b != '\0') {
        my_putchar(str[a]);
        a = a + 1;
        b = str[a];
    }
    return (0);
}
