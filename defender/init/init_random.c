/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** init_random.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "define.h"

int init_random(void)
{
    int fd = open("/dev/urandom", O_RDONLY);
    unsigned seed;

    if (fd == -1)
        return (ERROR);
    read(fd, &seed, sizeof seed);
    srand(seed);
    close(fd);
    return (SUCCESS);
}
