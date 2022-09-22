#include<stdlib.h>
#include <stdio.h>
int max(int a, int b) {
    return a > b ? a : b;
}
void Knapsack(int table[][100], int n, int W, int w[], int v[])
{
    for (int i = 0;i <= n;i++)
    {
        for (int j = 0;j <= W;j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (j - w[i] < 0)
                table[i][j] = table[i - 1][j];
            else
                table[i][j] = max(table[i - 1][j], v[i] + table[i - 1][j - w[i]]);
        }
    }
    printf(" table is \n");
    for (int i = 0;i <= n;i++)
    {
        for (int j = 0;j <= W;j++)
        {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }


}
void optimal(int table[][100], int n, int W, int w[], int v[])
{
    int i, j;
    if (table[n][W] == 0)
    {
        printf("\n not optimal ");
        return;
    }
    printf("optimal sol is %d", table[n][W]);
    printf("\n items included ");
    i = n;
    j = W;
    while (i != 0 && j != 0)
    {
        if (table[i][j] != table[i - 1][j]) {
            printf("%d\t", i);
            j = j - w[i];
        }
        i = i - 1;
    }
}
int main()
{
    int n, w[10], W, v[10];
    printf(" enter no of elements ");
    scanf("%d", &n);
    printf(" enter weight values : ");
    for (int i = 1;i <= n;i++)
        scanf("%d", &w[i]);
    printf(" enter val :");
    for (int i = 1;i <= n;i++)
        scanf("%d", &v[i]);
    printf(" enter the max weight or capacity ");
    scanf("%d", &W);
    int table[n + 1][W + 1];
    Knapsack(table, n, W, w, v);
    optimal(table, n, W, w, v);
    return 0;
}