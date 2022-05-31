#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the two arrays: ");
    scanf("%d", &n);

    int a[n][n];
    int b[n][n];
    int answer[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the value of a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the value of b%d%d: ", i + 1, j + 1);
            scanf("%d", &b[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            answer[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                answer[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\n\nThe resultant matrix looks like:\n\n");
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == n - 1)
                {
                    printf("%d\n", answer[i][j]);
                    break;
                }
                printf("%d\t", answer[i][j]);
            }
        }
    }

    return 0;
}