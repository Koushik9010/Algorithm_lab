#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define max_vertices 10

int i, j, n;

// Function to find the vertex with the minimum distance value
int minKey(int key[], bool mst[], int V) 
{
    int min = INT_MAX, min_index;

    // Loop through all vertices to find the minimum key
    for (int v = 0; v < V; v++) 
    {
        // Check if the vertex is not in the MST and has a smaller key
        if (!mst[v] && key[v] < min) 
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the MST
void printMST(int parent[], int graph[max_vertices][max_vertices], int V) 
{
    printf("Edge \tWeight\n");
    // Loop through all vertices starting from the second (1-indexed)
    for (int i = 1; i < V; i++) 
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Function to perform Prim's algorithm
void primMST(int graph[max_vertices][max_vertices], int V) 
{
    int parent[V], key[V];
    bool mst[V];

    // Initialize key values and MST set
    for (int i = 0; i < V; i++) 
    {
        key[i] = INT_MAX;
        mst[i] = false;
    }

    // Starting vertex has key 0
    key[0] = 0;
    parent[0] = -1;

    // Iterate to find MST
    for (int count = 0; count < V - 1; count++) 
    {
        // Find the vertex with the minimum key value
        int u = minKey(key, mst, V);
        mst[u] = true;

        // Update key values of adjacent vertices
        for (int v = 0; v < V; v++) 
        {
            // Update if the vertex is not in MST, there is an edge, and the weight is smaller
            if (graph[u][v] && !mst[v] && graph[u][v] < key[v]) 
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the MST
    printMST(parent, graph, V);
}

// Main function
int main() {
    printf("Enter the number of vertices (max %d): ", max_vertices);
    scanf("%d", &n);

    int graph[max_vertices][max_vertices];

    // Input the weighted graph adjacency matrix
    printf("Enter the weighted graph adjacency matrix (enter 0 if there is no edge):\n");
    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Perform Prim's algorithm
    primMST(graph, n);
    return 0;
}
