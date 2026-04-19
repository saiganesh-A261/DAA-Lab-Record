#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define V 5
#define E 6

struct Edge
{
    int src, dest, weight;
};
int parentUF[V];
int find(int i)
{
    if (parentUF[i] == i)
        return i;
    return find(parentUF[i]);
}
void unionSet(int u, int v)
{
    int rootU = find(u);
    int rootV = find(v);
    parentUF[rootU] = rootV;

int compare(const void *a, const void *b)
{
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}
void kruskalMST(struct Edge edges[])
{
    printf("\nKruskal's MST:\n");
    printf("Edge \tWeight\n");
    qsort(edges, E, sizeof(edges[0]), compare);
    for (int i = 0; i < V; i++)
        parentUF[i] = i;
    int count = 0;
    int total = 0;
    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;
        if (find(u) != find(v))
        {
            printf("%d - %d \t%d\n", u, v, edges[i].weight);
            total += edges[i].weight;

            unionSet(u, v);
            count++;
        }
    }
    printf("Total Cost = %d\n", total);
}
int main()
{
    struct Edge edges[E] = {
        {0, 1, 2},
        {0, 2, 3},
        {1, 2, 5},
        {1, 3, 3},
        {2, 4, 4},
        {3, 4, 2}};

    kruskalMST(edges);

    return 0;
}

// Code By @saiganesh-A261
