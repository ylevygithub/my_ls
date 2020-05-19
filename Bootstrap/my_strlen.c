/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** the lenght of the string
*/

#include "my.h"

int my_strlen(char *str)
{
    int nb;

    nb = 0;
    while (str[nb] != '\0')
        nb++;
    return (nb);
}
