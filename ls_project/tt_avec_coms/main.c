#include "my_ls"
int main(int ac, char **av)
{
    if (ac >= 2)
        my_ls(av[1]);
    return 0;
}
