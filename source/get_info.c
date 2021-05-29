/*
** EPITECH PROJECT, 2021
** N4S
** File description:
** get_info
*/

#include "n4s.h"

void make_distance_array(n4s_t *ai)
{
    ai->distance = calloc(sizeof(float), 32);

    for (int i = 0; i < 32; i++) {
        ai->distance[i] = atof(ai->info[i]);
    }
}

int get_info(n4s_t *ai)
{
    size_t len = 10;
    char *line = malloc(len);

    if (getline(&line, &len, stdin) == -1) {
        fprintf(stderr, "%sError: getline (get_info.c: l.21)%s\n", RED, WHITE);
        dprintf(1, "STOP_SIMULATION\n");
        getline(&line, &len, stdin);
        return -1;
    } if (strlen(line) < 90) {
        return -1;
    }
    ai->info = parser(line, ai);
    make_distance_array(ai);
    if (strcmp(ai->checkpoint, "Track Cleared") == 0) {
        ai->is_run = false;
        return 2;
    }
    return 0;
}