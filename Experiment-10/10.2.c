#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200

bool validPath(int n, int edges[][2], int edgeCount,
               int source, int destination) {
    if (n <= 0 || n > MAX_VERTICES ||
        source < 0 || destination < 0 ||
        source >= n || destination >= n ||
        edgeCount < 0 || edgeCount > MAX_EDGES) {
        return false;
    }

    // Build the undirected adjacency matrix.
    bool adj[MAX_VERTICES][MAX_VERTICES] = {false};

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        if (u < 0 || u >= n || v < 0 || v >= n) {
            return false;
        }

        adj[u][v] = true;
        adj[v][u] = true;
    }

    bool visited[MAX_VERTICES] = {false};
    int stack[MAX_VERTICES];
    int top = -1;

    stack[++top] = source;
    visited[source] = true;

    // Iterative Depth-First Search.
    while (top >= 0) {
        int node = stack[top--];

        if (node == destination) {
            return true;
        }

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (adj[node][neighbor] && !visited[neighbor]) {
                visited[neighbor] = true;
                stack[++top] = neighbor;
            }
        }
    }

    return false;
}

int main(void) {
    int n = 6;

    int edges[][2] = {
        {0, 1},
        {0, 2},
        {3, 5},
        {5, 4},
        {4, 3}
    };

    int edgeCount = (int)(sizeof(edges) / sizeof(edges[0]));
    int source = 0;
    int destination = 5;

    bool result = validPath(
        n, edges, edgeCount, source, destination
    );

    printf("Number of Vertices: %d\n", n);
    printf("Source: %d\n", source);
    printf("Destination: %d\n", destination);
    printf("Valid Path Exists: %s\n",
           result ? "true" : "false");

    return 0;
}
