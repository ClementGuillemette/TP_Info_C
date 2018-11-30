#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int pal = 0;

    printf("chaine: %s\n", arg);

    for(int i = 0; i < strlen(arg);i++)
    {
        if(arg[i] != arg[strlen(arg)-i-1])
        {
            pal = 1;
            break;
        }
    }

    return pal;
}

