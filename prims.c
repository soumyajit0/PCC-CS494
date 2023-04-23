#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int vertices;

void prims(int graph[vertices][vertices], int parent[], int edge[], bool visited[])
{
    int count;
    for (count = 0; count < vertices; count++)
    {
        int i, index = -1, min = INT_MAX;
        for (i = 0; i < vertices; i++)
        {
            if (visited[i] == false && edge[i] < min)
            {
                min = edge[i];
                index = i;
            }
        }
        visited[index] = true;
        for (i = 0; i < vertices; i++)
        {
            if (graph[index][i] <= edge[i] && graph[index][i] != 0 && visited[i] == false)
            {
                edge[i] = graph[index][i];
                parent[i] = index;
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
        if (parent[i] == -1)
            continue;
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