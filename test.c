#include<stdio.h>
#include<stdlib.h>
void prims(int n, int cost[10][10])
{
    int i, j, u, v, min, mincost = 0, visited[10], ne = 1;
    for (i = 1;i <= n;i++)
        visited[i] = 0;
    printf("Edges consider for Minimum Spanning Tree are:\n");
    visited[1] = 1;
    while (ne < n)
    {
        for (i = 1, min = 999;i <= n;i++)
            for (j = 1;j <= n;j++)
                if (cost[i][j] < min)
                {
                    if (visited[i] == 0)//not visited
                        continue;
                    else
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("%d Edges(%d,%d)=%d\n", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u] = 999;
    }
    printf("Cost of Constructing Minimum Spanning Tree is %d\n", mincost);
}
int main()
{
    int i, j, n, cost[10][10];
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    printf("Enter cost Matrix\n");
    for (i = 1;i <= n;i++)
    {
        for (j = 1;j <= n;j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }
    prims(n, cost);
    return 0;
}