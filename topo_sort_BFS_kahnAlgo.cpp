#include<bits/stdc++.h>

using namespace std;
int main()
{
 int V = 6; // Number of nodes in the graph
    // Create an array of vectors to represent the adjacency list
    std::vector<int> adj[V];
    // Add edges to the graph
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

vector<int> indegree(V,0);
vector<int> visited(V,0);
for(int i=0;i<V;i++){
    for(auto it: adj[i]){
        indegree[it]++;
    }
}

// kahn's algorithm
vector<int> ans;

// topo sort using bfs
queue<int> q;
for(int i=0;i<V;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}


for(int i=0;i<V;i++){

    if(!visited[i]){
while(!q.empty()){

int node= q.front();
q.pop();
visited[node]=1;
ans.push_back(node);
for(auto it: adj[node]){
    indegree[it]--;
    if(indegree[it]==0){
        q.push(it);
    }
}



}
    }

 
}

for(auto it: ans){
   cout<<it<<" ";
}



}