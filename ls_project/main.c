/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** main and time
*/

#include "my_ls.h"

void date_and_time(char *totaltime)
{
  int   count;

  count = 4;
  while (count < 16)
    {
      my_putchar(totaltime[count]);
      count++;
    }
}

int main(int ac, char **av)
{
    my_ls_by_choice(ac, av);
    if (ac >= 2 && av[1][0] == '-' && av[1][1] == 'l')
        my_ls_l(av[1]);
    if (ac == 1)
        my_ls(av[0]);
    return (0);
}
