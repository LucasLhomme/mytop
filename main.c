/*
** EPITECH PROJECT, 2024
** main of my project
** File description:
** main for my top project
*/

#include "my.h"
#include "struct.h"

int load_file(windows_t *window, float loadavg[], int i)
{
    write_pid_file();
    get_nb_user(window);
    get_my_loadavg(loadavg);
    header_top(window, loadavg);
    header_bot();
    return 0;
}

int main(int ch)
{
    windows_t window;
    float loadavg[3];
    int i;

    initscr();
    noecho();
    cbreak();
    curs_set(0);
    while (1) {
        clear();
        load_file(&window, loadavg, i);
        refresh();
        napms(1000);
        timeout(0);
        ch = getch();
        if (ch == 'q')
            break;
    }
    endwin();
    return 0;
}
