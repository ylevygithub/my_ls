/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls.c
*/

#include "my.h"

char *get_name2(char *pathname, int i)
{
    int n = 0;
    char *name = malloc(sizeof(char) * strlen(pathname) + 1);
    while (pathname[i] != '\0') {
        name[n] = pathname[i];
        i++;
        n++;
    }
    return (name);
}

char *get_name(char *pathname)
{
    int i = 0;
    char *name = malloc(sizeof(char) * strlen(pathname) + 1);
    int n = 0;

    while (pathname[i] != '\0')
        i++;
    while (pathname[i] != '/' && i > 0)
        i--;
    if (pathname[i] == '/')
        i++;
    name = get_name2(pathname, i);
    return (name);
}

char get_type(mode_t st_mode)
{
  switch (st_mode & S_IFMT)
  {
    case S_IFREG:  return('f');    break;
    case S_IFLNK:  return('l');    break;
    case S_IFBLK:  return('b');    break;
    case S_IFCHR:  return('c');    break;
    case S_IFSOCK:  return('s');    break;
    case S_IFIFO:  return('p');    break;
    case S_IFDIR:  return('d');    break;
    default: return ('?'); break;
  }
}

void info_file(char *pathname)
{
    struct stat sb;
    stat(pathname, &sb);
    char *name = get_name(pathname);   

    printf("Name: %s\n", name);
    printf("Type: %c\n", get_type(sb.st_mode));
    printf("Inode: %ld\n", sb.st_ino);
    printf("Hard Link: %ld\n", sb.st_nlink);
    printf("Size: %lld\n", sb.st_size);
    printf("Allocated Space: %lld\n", sb.st_blocks);
    if (get_type(sb.st_mode) == 'c')
    {
        printf("Minor: %d\n", minor(sb.st_rdev));
        printf("Major: %d\n", major(sb.st_rdev));
    } else {
        printf("Minor: N/A\n");
        printf("Major: N/A\n");
    }
    printf("UID: %ld\n", sb.st_uid);
    printf("GID: %ld\n", sb.st_gid);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        printf("error : wrong argument\n");
        return (84);
    }
    
    char *pathname = av[1];
    info_file(pathname);
    return 0;
}
