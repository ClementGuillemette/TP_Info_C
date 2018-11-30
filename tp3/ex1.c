#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        char *arg = argv[i];
        for (int j = 1; j <= strlen(arg); j++)
        {
            printf("%c", arg[strlen(arg) - j]);
        }
        printf("\n");
    }

    return 0;
}