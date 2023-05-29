#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int numVertices) {
        parent.resize(numVertices);
        rank.resize(numVertices);
        for (int i = 0; i < numVertices; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find the parent of a vertex (with path compression)
    int find(int v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    // Union of two sets (with rank-based optimization)
    void unionSets(int v1, int v2) {
        int root1 = find(v1);
        int root2 = find(v2);
        if (rank[root1] < rank[root2]) {
            parent[root1] = root2;
        } else if (rank[root1] > rank[root2]) {
            parent[root2] = root1;
        } else {
            parent[root2] = root1;
            rank[root1]++;
        }
    }
};

// Function to compare two edges based on their weights (for sorting)
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the minimum spanning weight using Kruskal's algorithm
int minimumSpanningWeight(vector<Edge>& edges, int numVertices) {
    sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(numVertices);

    int minSpanningWeight = 0;
    for (const Edge& edge : edges) {
        int srcParent = ds.find(edge.src);
        int destParent = ds.find(edge.dest);

        if (srcParent != destParent) {
            ds.unionSets(srcParent, destParent);
            minSpanningWeight += edge.weight;
        }
    }

    return minSpanningWeight;
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<Edge> edges;

    cout << "Enter the adjacency matrix representing the graph:\n";
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            int weight;
            cin >> weight;
            if (weight != 0 && i < j) { // Consider only the upper triangular matrix (to avoid duplicates)
                edges.push_back({i, j, weight});
            }
        }
    }

    int minSpanningWeight = minimumSpanningWeight(edges, numVertices);

    cout << "Minimum spanning weight: " << minSpanningWeight << "\n";

    return 0;
}
