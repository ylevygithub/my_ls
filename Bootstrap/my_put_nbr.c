/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int i;
    
    if (nb < 0 && nb != -2147483648) {
        write(1, "-", 1);
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
    return (0);
}
