/*
** EPITECH PROJECT, 2024
** header bottom 
** File description:
** header bottom for my_top
*/

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "../include/my.h"

int header_bot(void)
{


    attron(A_STANDOUT);
    mvprintw(5, 0, " PID USER  PR NI VIRT RES SHR S %%CPU %%MEM TIME+ COMMAND ");
    attroff(A_STANDOUT);

    return 0;
}