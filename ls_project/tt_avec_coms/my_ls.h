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
void my_ls(char *chemin);
/*
int stat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
int lstat(const char *pathname, struct stat *statbuf);
DIR *opendir(const char *name);
DIR *fdopendir(int fd);
int readdir(unsigned int fd, struct old_linux_dirent *dirp, unsigned int count);
int closedir(DIR *dirp);

struct passwd *getpwnam(const char *name);
struct passwd *getpwuid(uid_t uid);
int getpwnam_r(const char *name, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result);
int getpwuid_r(uid_t uid, struct passwd *pwd, char *buf, size_t buflen, struct passwd **result);

struct group *getgrnam(const char *name);
struct group *getgrgid(gid_t gid);
int getgrnam_r(const char *name, struct group *grp, char *buf, size_t buflen, struct group **result);
int getgrgid_r(gid_t gid, struct group *grp, char *buf, size_t buflen, struct group **result);

char *asctime(const struct tm *tm);
char *asctime_r(const struct tm *tm, char *buf);
char *ctime(const time_t *timep);
char *ctime_r(const time_t *timep, char *buf);

void *malloc(size_t size);
void free(void *ptr);

void perror(const char *s);
const char * const sys_errlist[];
int sys_nerr;
int errno;
char *strerror(int errnum);

int strerror_r(int errnum, char *buf, size_t buflen);  
char *strerror_r(int errnum, char *buf, size_t buflen);
char *strerror_l(int errnum, locale_t locale);

void _exit(int status);
*/

typedef struct s_list
{
    char *file_name;
    char *file_type;
    int inode;
    int hard_links;
    int file_size;
    int allocated_space;
    int minor;
    int major;
    int owners_UID;
    int owners_GID;
}t_list;
