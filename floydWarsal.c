#include <stdio.h>
#include <limits.h>

int V;

void floydWarshal(int graph[V][V])
{
    int i, j, k;
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            if (graph[i][j] == 0 && i != j)
            {
                graph[i][j] = INT_MAX;
            }
            else if (i == j)
            {
                graph[i][j] = 0;
            }
        }
    }
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if ((graph[i][k] + graph[k][j]) < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

int main()
{
    printf("Enter the no. of Vertices : ");
    scanf("%d", &V);
    int graph[V][V];
    int i, j, src;
    printf("Enter the Adjacency Matrix : \n");
    for (i = 0; i < V; i++)
    {
        for (j = 0; j < V; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    floydWarshal(graph);
    for (i = 0; i < V; i++)
    {
        if (graph[i][i] < 0)
        {
            printf("Negative Cycle exists\n");
            return 0;
        }
    }
    printf("Enter the Source Vertex : ");
    scanf("%d", &src);
    printf("Shortest Distances : \n");
    for (i = 0; i < V; i++)
    {
        printf("%d to %d = %d\n", src, i, graph[src][i]);
    }
}