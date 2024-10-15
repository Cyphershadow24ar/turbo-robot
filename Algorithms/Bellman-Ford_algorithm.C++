#include <iostream>
#include <vector>
#include <climits>  // This is used to define INT_MAX, representing infinity for unreachable nodes
using namespace std;

// Define a structure to represent an edge in a graph
// Each edge connects a source node (src), a destination node (dest), and has a weight (weight).
struct Edge {
    int src, dest, weight;
};

// The function that implements the Bellman-Ford algorithm
// This will find the shortest paths from a single source vertex to all other vertices
void bellmanFord(vector<Edge>& edges, int V, int E, int src) {
    // Step 1: Initialize distances from the source to all other vertices as INFINITY
    // and the distance to the source itself as 0
    vector<int> dist(V, INT_MAX);  // Vector to store distances
    dist[src] = 0;

    // Step 2: Relax all edges V-1 times (where V is the number of vertices)
    // Relaxing means checking if a shorter path exists, and if so, updating the distance
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;   // Starting vertex of the edge
            int v = edges[j].dest;  // Destination vertex of the edge
            int weight = edges[j].weight;  // Weight of the edge
            
            // If there's a shorter path to v via u, update distance of v
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    // After the above step, if you can still relax an edge, it means there's a negative-weight cycle
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative weight cycle!" << endl;
            return;
        }
    }

    // Step 4: Print the shortest distance from the source to all vertices
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << "\t\t" << "INF" << endl;  // Print "INF" for unreachable vertices
        } else {
            cout << i << "\t\t" << dist[i] << endl;  // Print the calculated distance
        }
    }
}

int main() {
    int V, E;

    // Input the number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Define a vector to store all edges in the graph
    vector<Edge> edges(E);

    // Get the edge details (source, destination, weight) from the user
    cout << "Enter the edges in the format (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        cout << "Edge " << i + 1 << ": ";
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int src;
    // Ask for the source vertex (the starting point for the algorithm)
    cout << "Enter the source vertex: ";
    cin >> src;

    // Call the Bellman-Ford function to calculate shortest paths
    bellmanFord(edges, V, E, src);

    return 0;
}
