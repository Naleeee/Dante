/*
** EPITECH PROJECT, 2021
** reader
** File description:
** read file and return content
*/

#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

char *my_reader(char const *filepath)
{
    struct stat *octet = malloc(sizeof(struct stat));
    int fd = open(filepath, O_RDONLY);
    char *buff;

    if (octet == NULL || fd == -1)
        return (NULL);
    stat(filepath, octet);
    buff = malloc(sizeof(char) * (octet->st_size + 1));
    if (buff == NULL)
        return (NULL);
    while ((read(fd, buff, octet->st_size)) < octet->st_size);
    close(fd);
    buff[octet->st_size] = '\0';
    return (buff);
}