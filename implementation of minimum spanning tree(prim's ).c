#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 5  // Number of vertices in graph
#define E 6  // Number of edges (not used here, but defined)

// Function to find vertex with minimum key value
// from the set of vertices not yet included in MST
int minKey(int key[], int visited[])
{
    int min = INT_MAX, min_index;

    for (int i = 0; i < V; i++)
    {
        // Select the smallest key value among unvisited vertices
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to print the constructed MST
void printPrimMST(int parent[], int graph[V][V])
{
    printf("\nPrim's MST:\n");
    printf("Edge \tWeight\n");

    int total = 0;

    // Start from 1 because 0 is root (no parent)
    for (int i = 1; i < V; i++)
    {
        // parent[i] -> i is the edge in MST
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }

    // Print total cost of MST
    printf("Total Cost = %d\n", total);
}

// Function to implement Prim's Algorithm
void primMST(int graph[V][V])
{
    int parent[V];   // Stores constructed MST
    int key[V];      // Key values to pick minimum weight edge
    int visited[V];  // Track vertices included in MST

    // Initialize all keys as infinite and visited as false
    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    // Start from vertex 0
    key[0] = 0;     // Make key 0 so that it is picked first
    parent[0] = -1; // Root node has no parent

    // MST will have V-1 edges
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum key vertex not yet included
        int u = minKey(key, visited);

        visited[u] = 1; // Include selected vertex in MST

        // Update key and parent of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            // Update only if:
            // 1. Edge exists (graph[u][v] != 0)
            // 2. Vertex not yet included
            // 3. Weight is smaller than current key
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the final MST
    printPrimMST(parent, graph);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}};

    // Call Prim's algorithm
    primMST(graph);

    return 0;
}

// Code By @saiganesh-A261