#include <stdio.h>
#include <stdbool.h>

#define NUM_VERTICES 6

int minDistance(int dist[], bool visited[]) {
    int min = INT_MAX, min_index;

    for (int vertex = 0; vertex < NUM_VERTICES; vertex++) {
        if (!visited[vertex] && dist[vertex] < min) {
            min = dist[vertex];
            min_index = vertex;
        }
    }

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < NUM_VERTICES; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[NUM_VERTICES][NUM_VERTICES], int src) {
    int dist[NUM_VERTICES];
    bool visited[NUM_VERTICES];

    for (int i = 0; i < NUM_VERTICES; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int count = 0; count < NUM_VERTICES - 1; count++) {
        int u = minDistance(dist, visited);

        visited[u] = true;

        for (int vertex = 0; vertex < NUM_VERTICES; vertex++) {
            if (!visited[vertex] && graph[u][vertex] && dist[u] != INT_MAX && dist[u] + graph[u][vertex] < dist[vertex]) {
                dist[vertex] = dist[u] + graph[u][vertex];
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[NUM_VERTICES][NUM_VERTICES];
    int src;

    printf("Enter the graph matrix:\n");
    for (int i = 0; i < NUM_VERTICES; i++) {
        for (int j = 0; j < NUM_VERTICES; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, src);

    return 0;
}
