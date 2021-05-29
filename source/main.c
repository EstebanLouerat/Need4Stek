/*
** EPITECH PROJECT, 2021
** n4s_package
** File description:
** main
*/

#include "n4s.h"

n4s_t init_n4s(void)
{
    n4s_t ai;

    ai.distance = NULL;
    ai.info = NULL;
    ai.checkpoint = NULL;
    ai.speed = .5f;
    ai.wheels = 0;
    ai.is_run = true;
    return ai;
}

void free_struct(n4s_t *ai)
{
    free(ai->info);
    free(ai->distance);
}

void start_or_end(int op)
{
    size_t len = BUF_SIZE;
    char *line = malloc(len);

    if (op == 0) {
        dprintf(1, "START_SIMULATION\n");
        my_getline();
        dprintf(1, "CAR_FORWARD:0.7\n");
        getline(&line, &len, stdin);
    } else if (op == 1) {
        dprintf(1, "START_SIMULATION\n");
        getline(&line, &len, stdin);
    }
    free(line);
}

int suite(n4s_t *ai)
{
    switch (get_info(ai)) {
    case -1:
        return 84;
    case 2:
        start_or_end(1);
        break;
    default:
        if (ai_movement(ai) == 2)
            start_or_end(1);
            break;
        break;
    }
}

int main(void)
{
    n4s_t ai = init_n4s();

    start_or_end(0);
    while (ai.is_run) {
        dprintf(1, "GET_INFO_LIDAR\n");
        if (suite(&ai) == 84)
            return 84;
    }
    start_or_end(1);
    free_struct(&ai);
    return 0;
}