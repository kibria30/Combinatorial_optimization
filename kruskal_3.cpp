#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int V);
    void addEdge(int src, int dest, int weight);
    int find(Subset subsets[], int i);
    void Union(Subset subsets[], int x, int y);
    void kruskalMST();
};

Graph::Graph(int V) {
    this->V = V;
}

void Graph::addEdge(int src, int dest, int weight) {
    Edge edge;
    edge.src = src;
    edge.dest = dest;
    edge.weight = weight;
    edges.push_back(edge);
}

int Graph::find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Graph::Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void Graph::kruskalMST() {
    vector<Edge> result;

    // Sort edges in non-decreasing order by weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });

    // Allocate memory for subsets
    Subset *subsets = new Subset[V];

    // Create V subsets with single elements
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    for (Edge edge : edges) {
        int x = find(subsets, edge.src);
        int y = find(subsets, edge.dest);

        // If including this edge does not cause cycle, include it in result and merge the subsets
        if (x != y) {
            result.push_back(edge);
            Union(subsets, x, y);
        }
    }

    // Print the result
    cout << "Minimum Spanning Tree:\n";
    for (Edge edge : result) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
    }

    delete[] subsets;
}

int main() {
    // Redirect input from a file
    freopen("kruskal_input.txt", "r", stdin);

    int V = 0; // Number of vertices
    Graph g(V);

    // Read edges from stdin
    char from, to;
    int weight;

    while (cin >> from >> to >> weight) {
        g.addEdge(from - 'a', to - 'a', weight); // Assuming vertices are represented by lowercase letters
        V = max(V, max(from - 'a', to - 'a') + 1); // Update the number of vertices
    }

    // Set the correct number of vertices in the graph
    g = Graph(V);

    // Run Kruskal's algorithm
    g.kruskalMST();

    return 0;
}
