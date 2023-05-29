#include <iostream>
#include <vector>

using namespace std;

const int INF = 99999;

// Function to implement Floyd-Warshall algorithm for all pair shortest paths
void floydWarshall(vector<vector<int>>& graph, int numVertices) {
    vector<vector<int>> dist(numVertices, vector<int>(numVertices));

    // Initialize the distance matrix with the input graph
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Compute the shortest distances between all pairs of vertices
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distance matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices));

    cout << "Enter the adjacency matrix representing the graph:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }

    floydWarshall(graph, numVertices);

    return 0;
}
