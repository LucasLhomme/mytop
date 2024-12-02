/*
** EPITECH PROJECT, 2024
** header top
** File description:
** header top for my_top
*/

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/my.h"

int write_date_to_file(windows_t *window, char *buffer, size_t buffer_size)
{
    struct tm *tmp_time = localtime(&window->t);

    time(&window->t);
    strftime(buffer, buffer_size, "%H:%M:%S", tmp_time);
    return 0;
}

int header_top(windows_t *window)
{
    char date_buffer[1000];

    write_date_to_file(window, date_buffer, sizeof(date_buffer));
    mvprintw(0, 0, "top - %s", date_buffer);
    return 0;
}
