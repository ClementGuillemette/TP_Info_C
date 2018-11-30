#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *arg = get_first_arg(argc, argv);

    printf("chaine: %s\n", arg);
    char tabtemp[strlen(arg)*2];    
    tabtemp[strlen(arg)*2-1]='\0';     

    for (int i = 0; i < strlen(arg); i++)
    {
        tabtemp[i + strlen(arg) - 1] = arg[i];
        tabtemp[strlen(arg) - 1 - i] = arg[i];
    }

    printf("chaine: %s\n", tabtemp);

    for(int i = 0; i<strlen(arg); i++)
    {
        tabtemp[i] = ' ';
        tabtemp[strlen(arg)*2 - 2 - i] = ' ';
        printf("chaine: %s\n", tabtemp);
    }
    
    return 0;
}