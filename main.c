/*
** EPITECH PROJECT, 2024
** main of my project
** File description:
** main for my top project
*/

#include <ncurses.h>

int main(void)
{
    initscr();
    printw("Hello World");
    refresh();
    getch();
    endwin();
    return 0;
}