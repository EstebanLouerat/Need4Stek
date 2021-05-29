/*
** EPITECH PROJECT, 2021
** B-AIA-200-LYN-2-1-n4s-ilhan.neuville
** File description:
** my_getline
*/

#include "n4s.h"

int my_getline(void)
{
    size_t len = 10;
    char *line = malloc(len);

    if (getline(&line, &len, stdin) == EOF) {
        exit(0);
    }
}