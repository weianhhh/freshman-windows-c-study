#define MAXSIZE 20
#include <stdio.h>


int main()
{
    int i, j, x = 0, sum = 0, n = 100;
    for (i = 1; i < n; i++)
    {
        printf("i=%d\n", i);
        for (j = 0; j < n; j++)
        {
            printf("j=%d\n", j);
            x++;
            printf("x=%d\n", x);
            sum += x;
            printf("sum=%d\n", sum);
        }
    }
    printf("%d\n", sum);
    return 0;
}
