/*
** EPITECH PROJECT, 2024
** struct for all my project !
** File description:
** keep all my struct for my project
*/

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

typedef struct my_struct_t {
    WINDOW *boite;
    WINDOW *haut;
    WINDOW *bas;
} my_struct_t;

#endif /* !MY_STRUCT_H_ */
