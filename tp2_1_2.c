#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int main()
{
    int i;
    double vt[N];
    double *p;
    srand(time(NULL));
    for (p = vt; p < vt + N; p++)
    {
        *p = 1 + rand() % 100;
        printf("%.f \n", *p);
    }

    return 0;
}