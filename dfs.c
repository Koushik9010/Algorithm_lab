#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int n;

// Function to create a graph
void createGraph() {
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nGraph created.\n");
}

// Modified DFS traversal
void dfs(int start) {
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (matrix[start][i] == 1 && visited[i] == 0) {
            printf("%d -> %d\n", start + 1, i + 1);
            dfs(i);
        }
    }
}

int main() {
    int choice, start;

    do {
        printf("\n********** MENU **********\n");
        printf("1. Create graph\n");
        printf("2. DFS traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                if (n == 0) {
                    printf("Please create a graph first.\n");
                } else {
                    printf("\nEnter the starting vertex for DFS: ");
                    scanf("%d", &start);
                    if (start >= 1 && start <= n) {
                        for (int i = 0; i < MAX_VERTICES; i++) {
                            visited[i] = 0;
                        }
                        dfs(start - 1);
                        printf("\n\n");
                    } else {
                        printf("Invalid starting vertex.\n");
                    }
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
