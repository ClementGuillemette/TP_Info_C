#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int ret_val = 0;
    char *arg = get_first_arg(argc, argv);
    printf("chaine : %s\n", arg);

    ret_val = convert(arg);

    return ret_val;
}  