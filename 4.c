#include<stdio.h>

int visited[10], order[10], orderC = 0, v[23], a[10][10];

void dfs(int a[10][10], int n, int src) {
    visited[src] = 1;
    for (int i = 0;i < n;i++) {
        if (a[src][i] == 1 && !visited[i]) {
            dfs(a, n, i);
            order[orderC++] = i;
        }
    }
}

void DFS(int a[10][10], int n, int src) {
    int c = n;
    while (c--) {
        if (!visited[src]) {
            dfs(a, n, src);
            order[orderC++] = src;
        }
        src = (src + 1) % n;
    }
}

void vertex_del(int in[], int v[], int n)
{
    int node;
    for (int k = 0;k < n;k++)
    {
        for (int i = 0;i < n;i++)
        {
            if (in[i] == 0 && v[i] == 0)
            {
                node = i;
                printf("%5d", node);
                v[node] = 1;
                break;
            }
        }
        for (int i = 0;i < n;i++)
        {
            if (a[node][i] == 1)
                in[i]--;
        }
    }
}
int main() {
    int n, src;
    int in[10] = { 0 };
    int v[10] = { 0 };
    printf("\nEnter number of nodes : ");
    scanf("%d", &n);
    printf("Enter adjacency matrix : \n");
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            scanf("%d", &a[i][j]);
            if (a[i][j] == 1)
                in[j]++;
        }
        
    }
    DFS(a, n, 0);
    printf("\nDFS Method\nTopological sort is : \n");
    for (int i = orderC;i > 0;i--) {
        printf("%d ", order[i - 1] + 1);
    }
    printf("\n");
    printf("Vertex Deletion method\nTopological Sort is :\n");
    vertex_del(in, v, n);
    return 0;
}