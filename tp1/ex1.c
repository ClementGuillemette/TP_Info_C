#include <stdio.h>
#include <stdlib.h>

char *get_first_arg(int argc, char *argv[])
{
    if (argc <2)
    {
        printf("no argument\n\n");
        exit(0);
    }
    return (argv[1]);
}

int main(int argc, char *argv[])
{
    char *arg = get_first_arg(argc, argv);

    printf("chaine : %s\n", arg);
    //puts(arg);
    int j = 0;

    while(arg[j] != 0)
    {
        j++;
    }
    printf("nombre de caractere : %d\n",j);

    return 0;
}

