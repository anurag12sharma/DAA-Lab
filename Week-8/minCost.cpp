#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum cost to connect cities using Prim's algorithm
int minimumCost(vector<vector<int>>& graph) {
    int numVertices = graph.size();

    vector<int> minCost(numVertices, INT_MAX); // Minimum cost to reach each vertex
    vector<bool> selected(numVertices, false); // Track which vertices are selected
    int totalCost = 0;

    // Start with the first vertex
    minCost[0] = 0;

    // Build the minimum spanning tree
    for (int count = 0; count < numVertices - 1; count++) {
        int minCostVertex = -1;
        for (int v = 0; v < numVertices; v++) {
            if (!selected[v] && (minCostVertex == -1 || minCost[v] < minCost[minCostVertex])) {
                minCostVertex = v;
            }
        }

        selected[minCostVertex] = true;
        totalCost += minCost[minCostVertex];

        // Update the minimum cost and select the next vertex
        for (int v = 0; v < numVertices; v++) {
            if (graph[minCostVertex][v] != 0 && !selected[v] && graph[minCostVertex][v] < minCost[v]) {
                minCost[v] = graph[minCostVertex][v];
            }
        }
    }

    return totalCost;
}

int main() {
    int numCities;
    cout << "Enter the number of cities: ";
    cin >> numCities;

    vector<vector<int>> graph(numCities, vector<int>(numCities, 0));

    cout << "Enter the adjacency matrix representing the graph:\n";
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            cin >> graph[i][j];
        }
    }

    int minCost = minimumCost(graph);

    cout << "Minimum cost required to connect the cities: " << minCost << " rupees\n";

    return 0;
}
