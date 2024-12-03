/*
** EPITECH PROJECT, 2024
** header top
** File description:
** header top for my_top
*/

#include "my.h"
#include "struct.h"

int write_date_to_file(windows_t *window, char *buffer, size_t buffer_size)
{
    struct tm *tmp_time;

    time(&window->t);
    tmp_time = localtime(&window->t);
    strftime(buffer, buffer_size, "%H:%M:%S", tmp_time);
    return 0;
}

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
    closedir(dir);
    return 0;
}

int get_my_loadavg(float *loadavg)
{
    FILE *file;

    file = fopen("/proc/loadavg", "r");
    if (file == NULL)
        return 84;
    if (fscanf(file, "%f %f %f", &loadavg[0], &loadavg[1], &loadavg[2]) != 3) {
        fclose(file);
        return 84;
    }
    fclose(file);
    return 0;
}

void header_top(windows_t *window, float *loadavg)
{
    char date_buffer[100];
    time_t now;
    struct tm *t;

    now = time(NULL);
    t = localtime(&now);
    strftime(date_buffer, sizeof(date_buffer) - 1, "%H:%M:%S", t);
    mvprintw(0, 0, "top - %s,", date_buffer);
    mvprintw(0, 15, " users %d,", window->user_count);
    mvprintw(0, 24, " load average: %.2f, %.2f, %.2f"
        , loadavg[0], loadavg[1], loadavg[2]);
}
