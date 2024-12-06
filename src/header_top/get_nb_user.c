/*
** EPITECH PROJECT, 2024
** get nb of user
** File description:
** get the number of user in ur pc
*/

#include "my.h"
#include "struct.h"

int get_nb_user(windows_t *window)
{
    struct dirent *entry;
    DIR *dir;

    window->user_count = 0;
    dir = opendir("/var/run/user/");
    if (dir == NULL)
        return 84;
    for (entry = readdir(dir); entry != NULL; entry = readdir(dir)) {
        if (entry->d_name[0] != '.')
            window->user_count++;
    }
    mvprintw(0, 15, " users %d,", window->user_count);
    closedir(dir);
    return 0;
}
