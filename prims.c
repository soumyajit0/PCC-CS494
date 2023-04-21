#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int vertices;

void prims(int graph[vertices][vertices], int parent[], int edge[], bool visited[])
{
    int i, j, index;
    for (int i = 0; i < vertices; i++)
    {
        int min = INT_MAX;
        for (j = 0; j < vertices; j++)
        {
            if (edge[j] <= min && visited[j] == false)
            {
                min = edge[j];
                index = j;
            }
        }
        visited[index] = true;
        for (j = 0; j < vertices; j++)
        {
            if (j == index)
                continue;
            if (graph[index][j] < edge[j] && graph[index][j] != 0)
            {
                edge[j] = graph[index][j];
                parent[j] = index;
            }
        }
    }
}

int MSTcost(int edge[])
{
    int i, cost = 0;
    for (i = 0; i < vertices; i++)
    {
        cost += edge[i];
    }
    return cost;
}

void MST(int parent[], int edge[])
{
    int i;
    for (i = 0; i < vertices; i++)
    {
        printf("Node %d -> Node %d = %d\n", parent[i], i, edge[i]);
    }
}

int main()
{
    int row, col, i;
    printf("Enter no. of vertices : ");
    scanf("%d", &vertices);
    int graph[vertices][vertices];
    printf("Enter the Adjacency Matrix : \n");
    for (row = 0; row < vertices; row++)
    {
        for (col = 0; col < vertices; col++)
        {
            scanf("%d", &graph[row][col]);
        }
    }
    int parent[vertices], edge[vertices];
    bool visited[vertices];
    for (i = 0; i < vertices; i++)
    {
        parent[i] = -1;
        edge[i] = INT_MAX;
        visited[i] = false;
    }
    edge[0] = 0;
    prims(graph, parent, edge, visited);
    printf("The cost of MST : %d\n", MSTcost(edge));
    printf("The MST is : \n");
    MST(parent, edge);
    return 0;
}