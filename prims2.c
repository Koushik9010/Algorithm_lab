#include<stdio.h>
#include<stdbool.h>
#include <string.h>

// Global variables
int i, j, n;

// Function to implement Prim's algorithm for Minimum Spanning Tree
void prims(int array[n][n])
{
    // Arrays and variables for tracking selected vertices and edges
    int selected[n], edge = 0, x, y;

    // Initialize 'selected' array to mark selected vertices, starting with vertex 0
    memset(selected, false, sizeof(selected));
    selected[0] = true;

    // Loop until all edges are selected for the Minimum Spanning Tree
    while(edge < n - 1)
    {
        // Initialize variables to find the minimum weight edge
        int min = 100000;
        x = 0;
        y = 0;

        // Iterate over selected vertices
        for(i = 0; i < n; i++)
        {
            // Check if the current vertex is selected
            if(selected[i])
            {
                // Iterate over all vertices
                for(j = 0; j < n; j++)
                {
                    // Check if the current vertex is not selected and there is an edge
                    if(!selected[j] && array[i][j])
                    {
                        // Check if the current edge has a smaller weight than the current minimum
                        if(min > array[i][j])
                        {
                            // Update minimum weight and corresponding vertices
                            min = array[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        // Print the selected edge and its weight
        printf("%d -> %d : %d\n", x, y, array[x][y]);

        // Mark the newly selected vertex as true
        selected[y] = true;

        // Increment the edge count
        edge++;
    }
}

// Main function
int main()
{
    // Input the number of vertices
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);

    // 2D array to store the adjacency matrix
    int array[n][n];

    // Input the adjacency matrix
    printf("Enter the adjacency matrix: \n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }

    // Call the function to perform Prim's algorithm
    prims(array);

    return 0;
}
