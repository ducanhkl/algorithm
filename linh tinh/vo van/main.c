#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long k, i;
int d[20];

int main()
{
    scanf("%lld", &k);
    while (k != 0)
        d[k%10]++, k /= 10;
    for (i = 1; i <= 9; i++)
        if (d[i] > 0)
            printf("%lld %d \n", i, d[i]);
    i = 0;
    if (d[i] > 0)
            printf("%lld %d \n", i, d[i]);
    return 0;
}
