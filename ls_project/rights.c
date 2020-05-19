/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** rights
*/

#include "my_ls.h"

void rights(struct stat *dp)
{
    ((dp->st_mode & S_IFDIR) != 0) ? my_putstr("d") : my_putstr("-");
    ((dp->st_mode & S_IRUSR) != 0) ? my_putstr("r") : my_putstr("-");
    ((dp->st_mode & S_IWUSR) != 0) ? my_putstr("w") : my_putstr("-");
    ((dp->st_mode & S_IXUSR) != 0) ? my_putstr("x") : my_putstr("-");
    ((dp->st_mode & S_IRGRP) != 0) ? my_putstr("r") : my_putstr("-");
    ((dp->st_mode & S_IWGRP) != 0) ? my_putstr("w") : my_putstr("-");
    ((dp->st_mode & S_IXGRP) != 0) ? my_putstr("x") : my_putstr("-");
    ((dp->st_mode & S_IROTH) != 0) ? my_putstr("r") : my_putstr("-");
    ((dp->st_mode & S_IWOTH) != 0) ? my_putstr("w") : my_putstr("-");
    ((dp->st_mode & S_IXOTH) != 0) ? my_putstr("x") : my_putstr("-");
}
