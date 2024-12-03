/*
** EPITECH PROJECT, 2024
** header bottom
** File description:
** header bottom for my_top
*/


#include "my.h"
#include "struct.h"

int write_pid_file(void)
{
    struct dirent *entry;
    int y = 6;
    DIR *dir = opendir("/proc/");

    if (dir == NULL) {
        mvprintw(6, 0, "tes nul");
        return 84;
    }
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (check_strisnum(entry->d_name[0]))
            mvprintw(y++, 0, "%s", entry->d_name);
    }
    closedir(dir);
    return 0;
}

int header_bot(void)
{
    attron(A_STANDOUT);
    mvprintw(5, 0, "PID USER  PR NI VIRT RES SHR S\
    %%CPU %%MEM TIME+ COMMAND ");
    attroff(A_STANDOUT);
    return 0;
}
