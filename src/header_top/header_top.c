/*
** EPITECH PROJECT, 2024
** header top
** File description:
** header top for my_top
*/

#include "my.h"
#include "struct.h"

int count_task(int i)
{
    struct dirent *entry;
    DIR *dir = opendir("/proc/");
    i = 0;

    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (check_strisnum(entry->d_name[0]))
            i++;
    }
    closedir(dir);
    return i;
}

void header_top(windows_t *window)
{
    char buffer[256];
    size_t buffer_size = sizeof(buffer);
    int task_count = count_task(0);
    float loadavg[3];

    write_hours(window, buffer, buffer_size);
    get_nb_user(window);
    get_my_loadavg(loadavg);
    mvprintw(1, 0, "Tasks: %d total,", task_count);
    refresh();
}

