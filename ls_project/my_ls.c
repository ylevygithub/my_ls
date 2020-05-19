/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my listing command
*/

#include "my_ls.h"

void display_all(struct dirent *dirent, struct stat source,
                 struct passwd *passwd, struct group *grp,
                 char *totaltime)
{
    my_putchar(' ');
    rights(&source);
    my_putstr(" ");
    my_put_nbr(source.st_nlink);
    my_putstr(" ");
    my_putstr(passwd->pw_name);
    my_putchar(' ');
    my_putstr(grp->gr_name);
    my_putchar(' ');
    my_put_nbr(source.st_size);
    my_putstr(" \t");
    date_and_time(totaltime);
    my_putstr(" ");
    my_putstr(dirent->d_name);
    my_putchar('\n');
}

void my_ls_l(char *chemin)
{
    DIR *dir;
    struct dirent *dirent;
    struct stat source;
    struct passwd *passwd;
    struct group *grp;
    char *totaltime;
    
    chdir(chemin);
    dir = opendir(".");
    if (chemin == NULL)
        exit(0);
    my_putstr("total");
    my_putchar('\n');
    while ((dirent = readdir(dir)) != 0)
    {
        if ((dirent->d_name[0] != '.'))
        {
            stat(dirent->d_name, &source);
            passwd = getpwuid(source.st_uid);
            grp = getgrgid(source.st_gid);
            totaltime = ctime(&(source.st_mtim.tv_sec));
            display_all(dirent, source, passwd, grp, totaltime);
        }
    }
    closedir(dir);
}

void my_ls(char *chemin)
{
    DIR *dir;
    struct dirent *dirent;
    struct stat source;

    chdir(chemin);
    dir = opendir(".");
    if (chemin == NULL)
        exit(0);
    while ((dirent = readdir(dir)) != 0)
    {
        if ((dirent->d_name[0] != '.'))
        {
            stat(dirent->d_name, &source);
            my_putstr(dirent->d_name);
            my_putchar(' ');
        }
    }
    my_putchar('\n');
}

void my_ls_r(char *chemin)
{
    DIR *dir;
    struct dirent *dirent;
    struct stat source;
 
    chdir(chemin);
    dir = opendir(".");
    if (chemin == NULL)
        exit (0);
    while ((dirent = readdir(dir)) != 0)
    {
        if ((dirent->d_name[0] != '.'))
        {
            stat(dirent->d_name, &source);
            my_putstr(dirent->d_name);
            my_putchar(' ');
        }
    }
    my_putchar('\n');
}

void my_ls_by_choice(int ac, char **av)
{
    if (ac >= 2 && av[1][0] != '-') {
        my_print_params(ac, av);
        my_putchar('\n');
    }
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'd')
        my_putstr(".\n");
    if (ac >= 2 && av[1][0] == '-' && av[1][1] == 'r')
        my_ls_r(av[1]);
}
