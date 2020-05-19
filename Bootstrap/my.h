/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <errno.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <time.h>

void info_file(char *);
int my_put_nbr(int );
int my_putstr(char *);
void my_putchar(char );
int my_strlen(char *);