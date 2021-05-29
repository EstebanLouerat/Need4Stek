/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** parse
*/

#include "n4s.h"

size_t count_sep(char *str, char sep)
{
    size_t count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == sep)
            count++;
    }
    return count + 1;
}

char **parser(char *str, n4s_t *ai)
{
    size_t size = count_sep(str, ':');
    char **tab = calloc(sizeof(char *), 32);
    char *tok;
    int i = 0, j = 0;

    tok = strtok(str, ":");
    while (tok != NULL) {
        tok = strtok(NULL, ":");
        j++;
        if (j > 2 && j < 35) {
            tab[i] = calloc(sizeof(char), 10);
            tab[i++] = tok;
        } if (j == 35) {
            ai->checkpoint = calloc(sizeof(char), BUF_SIZE);
            ai->checkpoint = tok;
        }
    }
    return tab;
}