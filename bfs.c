#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10 // Corrected the definition

int matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int n;
int front = -1, rear = -1;

// Function to create a graph
void createGraph() { // Renamed the function for consistency
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe graph is created...."); // Corrected the message
}

// Enqueue an element into the queue
void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("\nQueue is full");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = vertex;
    }
}

// Dequeue an element from the queue
int dequeue() {
    if (front == -1) {
        printf("\nQueue is empty.");
        return -1; // Added a return value to handle the empty queue case
    } else {
        int item = queue[front++];
        if (front > rear) {
            front = rear = -1;
        }
        return item;
    }
}

// Traversal
void bfs(int start) {
    printf("BFS traversal starts from vertex %d: \n", start + 1);
    enqueue(start);
    visited[start] = 1; // Corrected the initialization to 1

    while (front != -1) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex + 1);

        for (int i = 0; i < n; i++) {
            if (matrix[currentVertex][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n\n");
}

int main() {
    int choice, start;
    do {
        printf("\n**********MENU**********\n");
        printf("1. Create graph\n");
        printf("2. BFS traversal\n");
        printf("3. Exit\n");
        printf("Enter your choice: "); // Corrected the prompt message
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                if (n == 0) {
                    printf("\nPlease create the graph first\n");
                } else {
                    printf("\nEnter the starting vertex for bfs: ");
                    scanf("%d", &start);
                    if (start >= 1 && start <= n) {
                        for (int i = 0; i < MAX_VERTICES; i++) {
                            visited[i] = 0;
                        }
                        start = start - 1;
                        bfs(start);
                    } else {
                        printf("\nInvalid starting vertex.");
                    }
                }
                break;
            case 3:
                printf("\nExiting...\n"); // Corrected the exit message
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);
    return 0;
}
