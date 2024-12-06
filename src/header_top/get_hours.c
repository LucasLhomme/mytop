/*
** EPITECH PROJECT, 2024
** hours
** File description:
** wirte hours for top
*/

#include "my.h"
#include "struct.h"

int write_hours(windows_t *window, char *buffer, size_t buffer_size)
{
    struct tm *tmp_time;

    time(&window->t);
    tmp_time = localtime(&window->t);
    strftime(buffer, buffer_size, "%H:%M:%S", tmp_time);
    mvprintw(0, 0, "top - %s,", buffer);
    return 0;
}
