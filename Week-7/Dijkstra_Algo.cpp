#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a node in the graph
struct Node {
    int id;
    int distance;
};

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;
};

// Function to implement Dijkstra's algorithm
void dijkstra(vector<vector<Edge>>& graph, int source, vector<int>& distances, vector<int>& previous) {
    int n = graph.size();
    distances.assign(n, INT_MAX);
    previous.assign(n, -1);
    distances[source] = 0;

    priority_queue<Node, vector<Node>, function<bool(Node, Node)>> pq([](const Node& a, const Node& b) {
        return a.distance > b.distance;
    });

    pq.push({source, 0});

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int u = node.id;

        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
                pq.push({v, distances[v]});
            }
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
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<Edge>> graph(numNodes);

    cout << "Enter the edges in the format 'source destination weight':\n";
    for (int i = 0; i < numEdges; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph[source].push_back({destination, weight});
    }

    int sourceNode;
    cout << "Enter Akshay's house node: ";
    cin >> sourceNode;

    vector<int> distances, previous;
    dijkstra(graph, sourceNode, distances, previous);

    cout << "\nShortest distances from friends' locations to Akshay's house:\n";
    for (int i = 0; i < numNodes; i++) {
        cout << "Node " << i << ": ";
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
