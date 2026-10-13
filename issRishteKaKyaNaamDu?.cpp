#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

void addEdge(Node* adj[], int u, int v) {
    Node* newNode = new Node{v, adj[u]};
    adj[u] = newNode;

    // For an undirected graph
    newNode = new Node{u, adj[v]};
    adj[v] = newNode;
}

void BFS(Node* adj[], int V, int start) {
    bool* visited = new bool[V];

    for (int i = 0; i < V; i++)
        visited[i] = false;

    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        cout << curr << " ";

        Node* temp = adj[curr];
        while (temp != nullptr) {
            int neighbor = temp->vertex;

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }

            temp = temp->next;
        }
    }

    delete[] visited;
}

int main() {
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    Node** adj = new Node*[V];

    for (int i = 0; i < V; i++)
        adj[i] = nullptr;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    cout << "BFS Traversal: ";
    BFS(adj, V, start);

    // Free adjacency list memory
    for (int i = 0; i < V; i++) {
        Node* temp = adj[i];

        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }

    delete[] adj;
    return 0;
}
