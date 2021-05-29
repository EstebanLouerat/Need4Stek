/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Made by Vincent Daribo
*/

#include<unistd.h>

void my_putstr(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}
