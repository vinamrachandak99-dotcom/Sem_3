#include <iostream>
#include <vector>
using namespace std;

#define V 5  // number of vertices

// Function to check if vertex v can be added at position pos in the Hamiltonian cycle
bool isSafe(int v, const vector<vector<int>>& graph, const vector<int>& path, int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false; // No edge between last vertex and current vertex

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false; // Vertex already included

    return true;
}

// Recursive function to find Hamiltonian Cycle
bool hamCycleUtil(const vector<vector<int>>& graph, vector<int>& path, int pos) {
    if (pos == V) {
        // Check if the last vertex connects back to the first vertex
        return (graph[path[pos - 1]][path[0]] == 1);
    }

    // Try different vertices as next candidate
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamCycleUtil(graph, path, pos + 1))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Function to find and print Hamiltonian Cycle
void hamCycle(const vector<vector<int>>& graph, const string& graphName) {
    vector<int> path(V, -1);
    path[0] = 0; // Start from vertex A

    cout << "\n===== " << graphName << " =====" << endl;

    if (hamCycleUtil(graph, path, 1)) {
        cout << "Hamiltonian Cycle found:\n";
        for (int i = 0; i < V; i++)
            cout << char('A' + path[i]) << " -> ";
        cout << char('A' + path[0]) << endl;
    } else {
        cout << "No Hamiltonian Cycle exists for this graph.\n";
    }
}

int main() {

    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 0},  
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0}
    };

    cout << "===== Hamiltonian Cycle =====\n";
    hamCycle(graph1, "Graph 1");
    hamCycle(graph2, "Graph 2");

    return 0;
}
