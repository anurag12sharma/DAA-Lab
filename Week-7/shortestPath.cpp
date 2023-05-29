#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the weight of the shortest path with exactly k edges
int shortestPathWithKEdges(vector<vector<int>>& graph, int source, int destination, int k) {
    int numVertices = graph.size();
    vector<vector<int>> dp(numVertices, vector<int>(numVertices, INT_MAX));

    // Base case: When k = 0, the shortest path is just the edge weight from source to destination
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (i == j)
                dp[i][j] = 0;
            else if (graph[i][j] != 0)
                dp[i][j] = graph[i][j];
        }
    }

    // Dynamic programming: Compute the shortest path with k edges
    for (int edgeCount = 1; edgeCount <= k; edgeCount++) {
        vector<vector<int>> temp(numVertices, vector<int>(numVertices, INT_MAX));
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                for (int m = 0; m < numVertices; m++) {
                    if (dp[i][m] != INT_MAX && graph[m][j] != 0)
                        temp[i][j] = min(temp[i][j], dp[i][m] + graph[m][j]);
                }
            }
        }
        dp = temp;
    }

    return dp[source][destination];
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    cout << "Enter the graph in the form of adjacency matrix:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            cin >> graph[i][j];
        }
    }

    int source, destination, k;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> destination;
    cout << "Enter the number of edges (k): ";
    cin >> k;

    int shortestWeight = shortestPathWithKEdges(graph, source, destination, k);

    cout << "\nWeight of the shortest path from source to destination with exactly " << k << " edges: ";
    if (shortestWeight != INT_MAX)
        cout << shortestWeight;
    else
        cout << "No path exists";

    return 0;
}
