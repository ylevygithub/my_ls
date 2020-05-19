/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my listing command
*/

#include "my_ls.h"

void rights(struct stat *dp)
{
    ((dp->st_mode & S_IFDIR) != 0) ? my_putstr("d") : my_putstr("-"); //répertoire
    ((dp->st_mode & S_IRUSR) != 0) ? my_putstr("r") : my_putstr("-"); //permission de lecture, propriétaire
    ((dp->st_mode & S_IWUSR) != 0) ? my_putstr("w") : my_putstr("-"); //permission d'écriture, propriétaire
    ((dp->st_mode & S_IXUSR) != 0) ? my_putstr("x") : my_putstr("-"); //autorisation d'exécution / de recherche, propriétaire
    ((dp->st_mode & S_IRGRP) != 0) ? my_putstr("r") : my_putstr("-"); //autorisation de lecture, groupe
    ((dp->st_mode & S_IWGRP) != 0) ? my_putstr("w") : my_putstr("-"); //permission d'écriture, groupe
    ((dp->st_mode & S_IXGRP) != 0) ? my_putstr("x") : my_putstr("-"); //autorisation d'exécution / recherche, groupe
    ((dp->st_mode & S_IROTH) != 0) ? my_putstr("r") : my_putstr("-"); //autorisation de lecture, autres
    ((dp->st_mode & S_IWOTH) != 0) ? my_putstr("w") : my_putstr("-"); //permission d'écriture, autres
    ((dp->st_mode & S_IXOTH) != 0) ? my_putstr("x") : my_putstr("-"); //autorisation d'exécution / de recherche, autres
}

void my_ls(char *chemin)
{
    DIR *dir;
    struct dirent *dirent;
    struct stat sb;
    struct passwd *passwd;
    struct group *grp;
    //struct timespec st_mtim;
    char *mtime;
    
    chdir(chemin);
    dir = opendir(".");
    if (chemin == NULL)
    {
        exit(0);
    }
    my_putstr("total");
    my_putchar('\n');
    while ((dirent = readdir(dir)) != 0)
    {
        if ((dirent->d_name[0] != '.'))
        {
            stat(dirent->d_name, &sb);
            passwd = getpwuid(sb.st_uid);
            my_putchar(' ');
            rights(&sb);
            my_putstr("  ");
            my_put_nbr(sb.st_nlink);
            my_putstr("  ");
            my_putstr(passwd->pw_name);
            my_putchar(' ');
            grp = getgrgid(sb.st_gid);
            my_putstr(grp->gr_name);
            my_putchar(' ');
            my_put_nbr(sb.st_size);
            my_putstr(" ");
            //mtime = ctime(&(st_mtim.tv_sec));
            mtime = ctime(&(sb.st_mtim.tv_sec));
            my_putstr(mtime);
            //my_putstr(ctime(&sb->st_mtim));
            //write(1, mtime + 4, 12);
            my_putstr(" ");
            my_putstr(dirent->d_name);
            my_putchar('\n');
        }
    }
    closedir(dir);
}
int main(int ac, char **av)
{
    if (ac >= 2)
        my_ls(av[1]);
    return 0;
}
