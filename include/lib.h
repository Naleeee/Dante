/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** include proto of libmy.a
*/

#ifndef libmy
#define libmy

#include <stdarg.h>
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find, int i);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
unsigned int my_compute_power_rec(unsigned int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int  my_show_word_array(char * const *tab);
int my_put_float(int nb);
int my_memset(char *src, char c, int size);
int my_printf(char const *expr, ...);
int my_showoct(char const *str);
unsigned int my_put_unsigned_nbr(unsigned int nb);
unsigned int my_dec_to_hex_min(unsigned int nb);
unsigned int my_dec_to_hex_caps(unsigned int nb);
unsigned int my_dec_to_oct(unsigned int nb);
unsigned int my_dec_to_bin(unsigned int nb);
char find_letter(char const *expr, int i);
int flags_part5(char const *expr, int i, va_list list, char letter);
char **my_str_to_word_array(char const *str);
char **my_sort_word_array(char **tab, char **av);
char *my_str_replace(char *str, char *dest);
char *my_itoa(int result, char *str);
char **find_words(char *str);
char *my_reader(char const *filepath);

#endif