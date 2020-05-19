/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

void my_putchar(char );
void my_putstr(char *);
void my_put_nbr(int );

void rights(struct stat *dp);

void my_ls_l(char *chemin);
void my_ls(char *chemin);
void my_ls_by_choice(int ac, char **av);

void my_print_params(int ac, char **av);
void display_all(struct dirent *dirent, struct stat source, struct passwd *passwd, struct group *grp, char *totaltime);
void date_and_time(char *totaltime);
void my_ls_r(char *chemin);