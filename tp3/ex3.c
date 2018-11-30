#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(char *nb)
{
    int res = 0;
    for (int i = 0; i < strlen(nb); i++)
    {
        int pow = 1;
        if (i != 0)
        {
            for (int j = 1; j <= i; j++)
            {
                pow = pow * 10;
            }
        }
        res += (int)(((nb[strlen(nb) - 1 - i]) - 48) * pow);
    }
    return res;
}

int main(int argc, char *argv[])
{
    int value = convert(argv[1]);

    int tab[32] = {0};

    for (int i = 0; i < 32; i++)
    {
        tab[i] = value % 2;
        value /= 2;
    }

    for (int i = 0; i < 32; i++)
    {
        printf("%d", tab[31 - i]);
    }
    printf("\n");

    return 0;
}