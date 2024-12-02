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

int check_strisnum(char c)
{
    return (c >= '0' && c <= '9');
}

int write_pid_file(void)
{
    struct dirent *entry;
    int y = 6;
    DIR *dir = opendir("/proc/");

    if (dir != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (check_strisnum(entry->d_name[0])) {
                mvprintw(y++, 0, "%s", entry->d_name);
            }
        }
        closedir(dir);
        return 0;
    } else {
        mvprintw(6, 0, "tes nul");
        return 84;
    }
}

int header_bot(void)
{
    attron(A_STANDOUT);
    mvprintw(5, 0, "PID USER  PR NI VIRT RES SHR S\
    %%CPU %%MEM TIME+ COMMAND ");
    attroff(A_STANDOUT);

    return 0;
}