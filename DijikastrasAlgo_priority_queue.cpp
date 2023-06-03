#include<bits/stdc++.h>
using namespace std;
int comp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

typedef pair<int, int> pii; // pair of node and weight

vector<vector<pii>> adjacencyList;
int numNodes = 5;

void addEdge(int u, int v, int weight) {
    adjacencyList[u].push_back(make_pair(v, weight));
    adjacencyList[v].push_back(make_pair(u, weight)); // if the graph is undirected
}

int main() {
    // Resize the adjacency list to accommodate all nodes
    adjacencyList.resize(numNodes);

    // Adding edges
    addEdge(0, 1, 4);
    addEdge(0, 2, 1);
    addEdge(1, 3, 1);
    addEdge(2, 1, 2);
    addEdge(2, 3, 5);
    addEdge(3, 4, 3);

    vector<int> distance(V, INT_MAX);

   priority_queue<pii, vector<pii>, function<bool(pii, pii)>> pq([](pii a, pii b) {
        return a.second < b.second;
    });

    int src = 3;
    distance[src] = 0;
    pq.push({src, 0});

    while (!pq.empty()) {
        int node = pq.top().first;
        int weight = pq.top().second;
        pq.pop();

        if (weight > distance[node]) {
            continue;
        }

        for (auto it : adjacencyList[node]) {
            int nextNode = it.first;
            int nextWeight = it.second;

            if (distance[nextNode] > distance[node] + nextWeight) {
                distance[nextNode] = distance[node] + nextWeight;
                pq.push({nextNode, distance[nextNode]});
            }
        }
    }

    for (auto it : distance) {
        cout << it << " ";
    }

    return 0;
}
