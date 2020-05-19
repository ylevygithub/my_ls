/*
** EPITECH PROJECT, 2019
** lib
** File description:
** piscine functions
*/

#include "my_ls.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int nb = 0;
    
    while (str[nb] != '\0')
    {
        my_putchar(str[nb]);
        nb++;
    }
}

void my_put_nbr(int nb)
{
    int i;
    if(nb < 0 && nb != -2147483648) {
        my_putchar('-');
        i = -nb;
        my_put_nbr(i);
    }
    else if (nb == -2147483648) {
        write(1, "-2147483648", 11);
    }
    else {
        i = nb;
        if (i >= 10)
            my_put_nbr(i / 10);
        my_putchar(i % 10 + '0');
    }
}