#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *arg = get_first_arg(argc, argv);
    printf("chaine : %s\n", arg);

   upper(&arg[0], 1);

    for(int i = 0; i<strlen(arg); i++)
    {
        if(arg[i] == ' ')
        {
            printf("\n");
            upper(&arg[i+1],1);
            continue;
        }
        printf("%c",arg[i]);
    }
    printf("\n");
    
    return 0;
}