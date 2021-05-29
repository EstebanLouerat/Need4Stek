/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** my_put_arr
*/

#include "n4s.h"

void my_put_arr(char **tab)
{
    int i = 0;
    int j = 0;

    for (i = 0; tab[i] != NULL; i++) {
        for (j = 0; tab[i][j] != '\0'; j++) {
            if (tab[i][j] == '\n')
                write (2, "$", 1);
            else
                write(2, &tab[i][j], 1);
        }
        write(2, "\n", 1);
    }
}