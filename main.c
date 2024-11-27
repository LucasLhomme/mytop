/*
** EPITECH PROJECT, 2024
** main of my project
** File description:
** main for my top project
*/

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"

int main(void) {
    initscr();  // Initialise l'écran ncurses
    noecho();   // Désactive l'affichage des touches tapées
    cbreak();   // Désactive le buffering de ligne
    curs_set(0);

    while(1) {
        clear();  // Efface l'écran avant d'afficher le nouveau message
        header_bot();
        mvprintw(7, 0, "Le terminal actuel comporte %d lignes et %d colonnes", LINES, COLS);  // Imprime à la ligne 5, colonne 10
        refresh();  // Rafraîchit la fenêtre par défaut (stdscr) afin d'afficher le message
        int ch = getch();  // Attend une entrée de l'utilisateur
        if(ch == 'q')  // Quitte la boucle si la touche 'q' est pressée
            break;
    }

    endwin();  // Restaure les paramètres du terminal avant la fin du programme
    return 0;
}