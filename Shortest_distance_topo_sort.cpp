#include<bits/stdc++.h>
using namespace std;

void topo(int node, stack<int> &st, vector<pair<int,int>> adj[], int visited[]) { // Corrected the typo in the parameter name

    visited[node] = 1;

    for(auto it: adj[node]) {
        if(!visited[it.first]) {
            topo(it.first, st, adj, visited);
        }
    }
    st.push(node);
}

int main() {
    vector<vector<int>> edge = {
        {0, 1, 2},
        {0, 4, 1},
        {4, 5, 4},
        {4, 2, 2},
        {1, 2, 3},
        {2, 3, 6},
        {5, 3, 1}
    };
    int M = 7;
    int N = 7;

    vector<pair<int,int>> adj[N]; // Changed the size to N to match the number of nodes

    for(int i = 0; i < M; i++) {
        adj[edge[i][0]].push_back({edge[i][1], edge[i][2]});
    }

    stack<int> st;
    int visited[N] = {0};

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            topo(i, st, adj, visited);
        }
    }

    vector<int> distance(N, 1e9);
    distance[0] = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();
        for(auto it : adj[node]) {
            if(distance[it.first] > it.second + distance[node]) {
                distance[it.first] = it.second + distance[node];
            }
        }
    }

    // Rest of the code is missing, you might want to print or utilize the 'distance' vector
    for(auto it: distance){
        cout<<it<<" ";
    }
    return 0;
}