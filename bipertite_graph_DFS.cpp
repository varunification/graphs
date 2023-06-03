#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<int> adj[], vector<int>& visited, int node, int parent) {
    if(parent==-1){
        visited[node] =1;
    }
    if (parent!=-1 && visited[node] == visited[parent]) {
        return false;
    }
    visited[node] = !visited[parent];

    for (auto adjacentNode : adj[node]) {
        if (visited[adjacentNode] == -1) {
            if (!DFS(adj, visited, adjacentNode, node)) {
                return false;
            }
        } else if (visited[node] == visited[adjacentNode]) {
            return false;
        }
    }

    return true;
}

int main()
{
vector<int>adj[4];
      adj[0] = {1,3};
      adj[1] = {0,2};
      adj[2] = {1,3};
      adj[3] = {0,2};

vector<int>visited(4, -1);

bool flag = true;
for(int i=0;i<4;i++){
    if(visited[i]==-1){
    flag = DFS(adj, visited, i,-1);
    if(!flag){
        break;
    }
    }
}

if(flag){
    cout<<"graph is bipertite";
}
else{
    cout<<"graph is not bipertite";
}



 return 0;
}