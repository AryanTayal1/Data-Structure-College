//Get the number of vertices of a graph and adjacency matrix. Check if the graph is a digraph or undirected graph

#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int adj[MAX][MAX];
int n;
bool symmetric(int n, int arr[][MAX])
{
    int c, d, transpose[10][10];
    for (c = 0; c < n; c++)
        for (d = 0; d < n; d++)
            transpose[d][c] = arr[c][d];
    for (c = 0; c < n; c++)
    {
        for (d = 0; d < n; d++)
        {
            if (arr[c][d] != transpose[c][d])
                break;
        }
        if (d != n)
            break;
    }
    if (c == n)
        return true;
    else
        return false;
}
int main()
{
    int max_edges, i, j, origin, destin;
    printf("\nEnter number of vertices :: ");
    scanf("%d", &n);
    max_edges = n * (n - 1) / 2;
    for (i = 1; i <= max_edges; i++)
    {
        printf("\nEnter edge [ %d ] ( -1 -1 to quit ) : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == -1) && (destin == -1))
            break;
        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("\nInvalid vertex!\n");
            i--;
        }
        else
        {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1;
        }
    }
    printf("\nThe adjacency matrix is :: \n");
    for (i = 0; i <= n - 1; i++)
    {
        for (j = 0; j <= n - 1; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
    if (symmetric(n, adj) == true)
        printf("The graph is unidirected");
    else
        printf("The graph is not unidirected");
}
