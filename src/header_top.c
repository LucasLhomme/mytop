/*
** EPITECH PROJECT, 2024
** header top
** File description:
** header top for my_top
*/

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

int header_top(void)
{
    attron(A_STANDOUT);
    mvprintw(5, 0, " PID USER  PR NI VIRT RES SHR S %%CPU %%MEM TIME+ COMMAND ");
    attroff(A_STANDOUT);

    return 0;
}