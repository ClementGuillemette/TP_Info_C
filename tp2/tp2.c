#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* upper(char *s, int size)
{
    for( int i = 0; i<size; i++)
    {
        if(s[i] > 96 && s[i] < 123)
        {
            s[i] -= 32;
        }
    }

    return s;
}

char *get_first_arg(int argc, char *argv[])
{
    if (argc <2)
    {
        printf("no argument\n\n");
        exit(0);
    }
    return (argv[1]);
}

int convert(char *nb)
{
    int res = 0;
    for(int i = 0; i < strlen(nb); i++)
   {
       int pow = 1;
       if(i != 0)
       {
            for(int j = 1; j<=i ; j++)
            {
                pow = pow * 10;
                //printf("%d",pow);
            }
       }
       res += (int)(((nb[strlen(nb)-1-i])-48)*pow);
   }
   return res;
}