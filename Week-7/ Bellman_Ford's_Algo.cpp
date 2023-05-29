#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source;
    int destination;
    int weight;
};

// Function to implement Bellman-Ford algorithm
void bellmanFord(vector<Edge>& edges, int numVertices, int source, vector<int>& distances, vector<int>& previous) {
    distances.assign(numVertices, INT_MAX);
    previous.assign(numVertices, -1);
    distances[source] = 0;

    // Relax edges repeatedly
    for (int i = 0; i < numVertices - 1; i++) {
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
            }
        }
    }

    // Check for negative-weight cycles
    for (const Edge& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
            // Negative-weight cycle found
            cout << "Negative-weight cycle detected. The graph contains a negative cycle.\n";
            return;
        }
    }
}

// Function to print the shortest path from source to destination
void printShortestPath(vector<int>& previous, int destination) {
    if (previous[destination] != -1) {
        printShortestPath(previous, previous[destination]);
    }
    cout << destination << " ";
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<Edge> edges(numEdges);

    cout << "Enter the edges in the format 'source destination weight':\n";
    for (int i = 0; i < numEdges; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;

    vector<int> distances, previous;
    bellmanFord(edges, numVertices, sourceVertex, distances, previous);

    cout << "\nShortest paths from destination vertices to the source vertex:\n";
    for (int i = 0; i < numVertices; i++) {
        cout << "Destination " << i << ": ";
        if (distances[i] != INT_MAX) {
            cout << distances[i] << " (Shortest path: ";
            printShortestPath(previous, i);
            cout << ")";
        } else {
            cout << "Not reachable";
        }
        cout << endl;
    }

    return 0;
}
