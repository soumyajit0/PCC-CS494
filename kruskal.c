#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int V, E;

struct node
{
    int node1;
    int node2;
    struct node *next;
};

struct node *insert(struct node *head, int u, int v)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->node1 = u;
    temp->node2 = v;
    if (head == NULL)
        return temp;
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    return head;
}

int findPar(int node, int parent[])
{
    if (node == parent[node])
        return node;
    return parent[node] = findPar(parent[node], parent);
}

void unionBySize(int u, int v, int parent[], int size[])
{
    int x = findPar(u, parent);
    int y = findPar(v, parent);
    if (x == y)
        return;
    else if (size[x] > size[y])
    {
        parent[y] = x;
        size[x] += size[y];
    }
    else
    {
        parent[x] = y;
        size[y] += size[x];
    }
}

struct node *kruskal(int adj[E][3], int parent[], int size[], struct node *head)
{
    int count, i, MSTCost = 0;
    int final[E];
    for (i = 0; i < E; i++)
    {
        final[i] = 0;
    }
    for (count = 0; count < E; count++)
    {
        int index = -1, mn = INT_MAX;
        for (i = 0; i < E; i++)
        {
            if (adj[i][2] < mn && final[i] == 0)
            {
                index = i;
                mn = adj[i][2];
            }
        }
        final[index] = 1;
        int u = adj[index][0];
        int v = adj[index][1];
        int w = adj[index][2];
        if (findPar(u, parent) != findPar(v, parent))
        {
            unionBySize(u, v, parent, size);
            head = insert(head, u, v);
            MSTCost += w;
        }
    }
    printf("The Cost of MST is : %d\n", MSTCost);
    return head;
}

int main()
{
    struct node *head = NULL;
    int i;
    printf("Enter the no. of Vertices and Edges : ");
    scanf("%d %d", &V, &E);
    int adj[E][3];
    printf("Enter the Source, Destination and Cost of each Edge : \n");
    for (i = 0; i < E; i++)
    {
        scanf("%d %d %d", &adj[i][0], &adj[i][1], &adj[i][2]);
    }
    int parent[V], size[V];
    for (i = 0; i < V; i++)
    {
        parent[i] = i;
        size[i] = 1;
    }
    head = kruskal(adj, parent, size, head);
    printf("The MST is : \n");
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d -> %d\n", ptr->node1, ptr->node2);
        ptr = ptr->next;
    }
    return 0;
}