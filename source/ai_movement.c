/*
** EPITECH PROJECT, 2021
** N4S
** File description:
** ai_movement
*/

#include "n4s.h"

int ai_backwards(n4s_t *ai)
{
    size_t len = BUF_SIZE;
    char *line = malloc(len);

    my_putstr("WHEELS_DIR:0.0\n");
    getline(&line, &len, stdin);
    while (ai->distance[0] <= 200 || ai->distance[31] <= 200 ||
    ai->distance[MID] <= 200) {
        my_putstr("GET_INFO_LIDAR\n");
        get_info(ai);
        my_putstr("CAR_BACKWARDS:0.8\n");
        getline(&line, &len, stdin);
    }
    my_putstr("CAR_FORWARD:0.4\n");
    getline(&line, &len, stdin);
    free(line);
}

int ai_turn_left(n4s_t *ai)
{
    size_t len = BUF_SIZE;
    char *line = malloc(len);

    my_putstr("WHEELS_DIR:0.3\n");
    getline(&line, &len, stdin);
    while (ai->distance[MID] < 900 && ai->distance[0] > ai->distance[31]) {
        my_putstr("GET_INFO_LIDAR\n");
        if (get_info(ai) == 2)
            return 2;
        if (ai->distance[0] < 10 || ai->distance[31] < 10 ||
        ai->distance[MID] < 10) {
            ai_backwards(ai);
            break;
        }
    }
    my_putstr("WHEELS_DIR:0.0\n");
    getline(&line, &len, stdin);
    my_putstr("CAR_FORWARD:0.8\n");
    getline(&line, &len, stdin);
    free(line);
    return 0;
}

int ai_turn_right(n4s_t *ai)
{
    size_t len = BUF_SIZE;
    char *line = malloc(len);

    my_putstr("WHEELS_DIR:-0.3\n");
    getline(&line, &len, stdin);
    while (ai->distance[MID] < 900 && ai->distance[0] < ai->distance[31]) {
        my_putstr("GET_INFO_LIDAR\n");
        if (get_info(ai) == 2)
            return 2;
        if (ai->distance[0] < 10 || ai->distance[31] < 10 ||
        ai->distance[MID] < 10) {
            ai_backwards(ai);
            break;
        }
    }
    my_putstr("WHEELS_DIR:0.0\n");
    getline(&line, &len, stdin);
    my_putstr("CAR_FORWARD:0.8\n");
    getline(&line, &len, stdin);
    return 0;
}

int ai_movement(n4s_t *ai)
{
    size_t len = BUF_SIZE;
    char *line = malloc(len);

    if (ai->distance[MID] < 1500) {
        my_putstr("CAR_FORWARD:0.4\n");
        getline(&line, &len, stdin);
    } if (ai->distance[MID] < 800) {
        my_putstr("CAR_FORWARD:0.2\n");
        getline(&line, &len, stdin);
        if (ai->distance[0] < ai->distance[31])
            return ai_turn_right(ai);
        else
            return ai_turn_left(ai);
    }
}