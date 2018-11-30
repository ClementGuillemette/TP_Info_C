#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *arg = get_first_arg(argc, argv);
    printf("chaine : %s\n", arg);

   upper(arg, strlen(arg));
    printf("Majuscule : %s\n", arg);


    return 0;
}