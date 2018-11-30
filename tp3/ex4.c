#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_complex
{
    double r;
    double i;
} t_complex;

double convert(char *nb)
{
    double res = 0;
    for (int i = 0; i < strlen(nb); i++)
    {
        double pow = 1;
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

t_complex *c_add(t_complex *op1, t_complex *op2)
{
    t_complex *complexC = malloc(1 * sizeof(t_complex));

    complexC->i = op1->i + op2->i;
    complexC->r = op1->r + op2->r;

    return complexC;
}

int main(int argc, char *argv[])
{
    double value = convert(argv[1]);
    double value2 = convert(argv[2]);
    double value3 = convert(argv[3]);
    double value4 = convert(argv[4]);

    t_complex nb1 = {value, value2};
    t_complex nb2 = {value3, value4};

    t_complex *nb3 = c_add(&nb1, &nb2);


    printf("%.0f + %.0fi\n", nb3->r, nb3->i);
    free(nb3);
    
    return 0;
}