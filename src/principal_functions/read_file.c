/*
** EPITECH PROJECT, 2021
** read_file
** File description:
** read map file
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "runner.h"

int measure_size(char *str)
{
    struct stat buffsize;

    stat(str, &buffsize);
    return (buffsize.st_size);
}

int read_file(char *file, game_variables_t *g)
{
    int size = measure_size(file);
    int fd = open(file, O_RDONLY);

    g->buff = malloc(sizeof(char) * (size + 1));
    if (g->buff == NULL || fd == -1 || size != 20)
        return (84);
    read (fd, g->buff, size);
    g->buff[size] = '\0';
    close (fd);
    return (0);
}