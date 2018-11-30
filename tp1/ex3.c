#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_first_arg(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("no argument\n\n");
        exit(0);
    }
    return (argv[1]);
}

int main(int argc, char *argv[])
{
    char *arg = get_first_arg(argc, argv);

    printf("chaine: %s\n", arg);
    char tabtemp[strlen(arg) * 2 - 3];
    for (int i = 0; i < strlen(arg) * 2 - 2; i++)
    {
        tabtemp[i] = ' ';
    }

    for (int i = 0; i < strlen(arg); i++)
    {
        tabtemp[i + strlen(arg) - 1] = arg[i];
        tabtemp[strlen(arg) - 1 - i] = arg[i];
        printf("chaine: %s\n", tabtemp);
    }

    return 0;
}
