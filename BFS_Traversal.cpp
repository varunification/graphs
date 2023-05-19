#include<bits/stdc++.h>

using namespace std;
void DFS(int V, vector<int> adj[], vector<int>& visited, int node) {
    visited[node] = 1;
    cout << node << " ";

    for (auto it : adj[node]) {
        if (!visited[it]) {
            DFS(V, adj, visited, it);
        }
    }
}

// Function to add an edge to the adjacency list
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to generate a random connected graph with n nodes
vector<int>* generateGraph(int n) {
    // Seed the random number generator
    srand(time(0));
    // Create an adjacency list
    vector<int>* adj = new vector<int>[n];
    
    // Connect all nodes in a random order
    vector<int> nodes;
    for (int i = 0; i < n; i++) {
        nodes.push_back(i);
    }
    //shuffle(nodes.begin(), nodes.end());
    
    // Add edges to connect the nodes
    for (int i = 0; i < n - 1; i++) {
        addEdge(adj, nodes[i], nodes[i + 1]);
    }
    
    // Add a random edge to connect the last and first nodes
    addEdge(adj, nodes[n - 1], nodes[0]);
    
    return adj;
}

// Function to print the adjacency list
void printGraph(vector<int> adj[], int n) {
    vector<int> visited(n, 0);
    queue<int> bfsqueue;
    bfsqueue.push(0); // Starting with vertex 0

    while (!bfsqueue.empty()) {
        int temp = bfsqueue.front();
        bfsqueue.pop();
        cout << temp << " ";
        for (int i = 0; i < adj[temp].size(); i++) {
            if (!visited[adj[temp][i]]) {
                bfsqueue.push(adj[temp][i]);
                visited[adj[temp][i]] = 1; // Mark as visited
            }
        }
    }
    cout<<"\n";
}


// void bfs(vector<int> adj[], int n, int i){
//   queue<int> q;

// q.add(adj[i]);

// while (!q.empty())
// {
//     if(!visited[adj[i][0]]){
//        cout<<q.front();
//        int temp = q.front;
//        q.pop();
//     }

// for(int i=0;i<2;i++){
//     q.push(adj[i][0]);
//     q.push(adj[i][1]);
// }
// }
// }


int main() {
    int n = 12; // Number of nodes
    vector<int>* adj = generateGraph(n);
    printGraph(adj, n);
    vector<int> visited(n,0);
    DFS(n,adj, visited, 0);
    delete[] adj;    
    return 0;
}
