/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** n4s
*/

#ifndef N4S_H__
#define N4S_H__

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

#define RED     "\e[31;1m"
#define WHITE   "\e[0m"
#define MID     16
#define BUF_SIZE    32

typedef struct n4s_s
{
    char **info;
    char *checkpoint;
    float *distance;
    float speed;
    float wheels;
    bool is_run;
}n4s_t;

//////////// lib ////////////////

char **parser(char *str, n4s_t *ai);
void my_put_arr(char **tab);
void my_putstr(char const *str);
int my_getline(void);

/////////////////////////////////

int get_info(n4s_t *ai);
int ai_movement(n4s_t *ai);

#endif