/*
** EPITECH PROJECT, 2024
** get my loadavg
** File description:
** get the load average of my pc
*/

#include "my.h"
#include "struct.h"

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
    mvprintw(0, 24, " load average: %.2f, %.2f, %.2f"
        , loadavg[0], loadavg[1], loadavg[2]);
    fclose(file);
    return 0;
}
