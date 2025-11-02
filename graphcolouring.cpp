#include <iostream>
#include <vector>
using namespace std;

#define V 5 // number of vertices

// Function to check if current color assignment is valid
bool isSafe(int v, const vector<vector<int>> &graph, const vector<int> &color, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Recursive utility function for coloring the graph
bool graphColorUtil(const vector<vector<int>> &graph, int m, vector<int> &color, int v) {
    // If all vertices are assigned a color then return true
    if (v == V)
        return true;

    // Try assigning all colors from 1 to m
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColorUtil(graph, m, color, v + 1))
                return true;

            // Backtrack
            color[v] = 0;
        }
    }

    return false;
}

// Function to solve the Graph Coloring problem
void graphColoring(const vector<vector<int>> &graph, int m, string name) {
    vector<int> color(V, 0);

    cout << "\n===== " << name << " =====" << endl;

    if (graphColorUtil(graph, m, color, 0)) {
        cout << "Color assignment for vertices:\n";
        for (int i = 0; i < V; i++)
            cout << "Vertex " << char('A' + i) << " --> Color " << color[i] << endl;
    } else {
        cout << "No solution exists using " << m << " colors.\n";
    }
}

// Main function
int main() {
    cout << "=====  Graph Coloring =====\n";

    vector<vector<int>> graph1 = {
        {0, 1, 1, 0, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 0, 0, 1, 0}};
        
    vector<vector<int>> graph2 = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 1, 1, 1, 0}};

    graphColoring(graph1, 3, "Graph 1");
    graphColoring(graph2, 5, "Graph 2");

    return 0;
}
