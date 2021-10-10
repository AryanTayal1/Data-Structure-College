//Write a menu driven program to obtain vertex IDs in a character array and adjacency matrix of a digraph and an undirected graph. Implement separate funvtions to display; (a) Degree of all vertices of the undirected graph, (b) In degree and out degree of all the vertices of the digraph (c) Adjacency matrices.

#include <stdio.h>
#include <stdbool.h>
#define MAX 10

int adj[MAX][MAX];
int n;
int choice, num, i;
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
    while(1)
    {
        printf("1. Adjacency matrices. \n");
        printf("2. Degree of all vertices of the undirected graph, \n");
        printf("3. In degree and out degree of all the vertices of the digraph\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                 printf("\nThe adjacency matrix is :: \n");
                for (i = 0; i <= n - 1; i++)
                {
                    for (j = 0; j <= n - 1; j++)
                        printf("%4d", adj[i][j]);
                    printf("\n");
                }
            case 2:
                if (symmetric(n, adj) == true)
                printf("The graph is unidirected");
                else
                printf("The graph is not unidirected");
        
            case 3:
                if (symmetric(n, adj) == true)
                printf("The graph is unidirected");
                else
                printf("The graph is not unidirected");
                }
    }
    return 0;
}
