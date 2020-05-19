/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        my_putchar(str[nb]);
        nb = nb + 1;
    }
    return (0);
}
