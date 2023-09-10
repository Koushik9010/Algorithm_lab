#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int n;

void createGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Graph created.\n");
}

void bfs(int start) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    printf("BFS traversal starting from vertex %d:\n", start + 1);

    visited[start] = 1;
    printf("%d ", start + 1);
    queue[rear++] = start;

    while (front < rear) {
        int currentVertex = queue[front++];

        for (int i = 0; i < n; i++) {
            if (graph[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i + 1);
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

int main() {
    int choice, start;

    do {
        printf("************ MENU ************\n");
        printf("1. Create Graph\n");
        printf("2. BFS Traversal\n");
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
                    printf("Enter the starting vertex for BFS: ");
                    scanf("%d", &start);
                    if (start >= 1 && start <= n) {
                        for (int i = 0; i < n; i++) {
                            visited[i] = 0;
                        }
                        bfs(start - 1);
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
