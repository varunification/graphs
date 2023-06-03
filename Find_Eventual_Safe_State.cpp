#include<bits/stdc++.h>
using namespace std;

bool DFS(vector<int>adj[], vector<int> &visited, vector<int> & path, vector<int> &ans, int node){
    visited[node]=1;
    path[node]=1;
    ans[node]=0;
    for(auto adjnodes: adj[node]){
        if(!visited[adjnodes]){
            if(DFS(adj, visited, path, ans,adjnodes)==true){
                // ans[node]=0;
                return true;
            }
        }
     else if(path[adjnodes]==1){
         //ans[node]=0;
        return true;
     }
    }
    ans[node]=1;
    path[node]=0;
    return false;
}


int main()
{
vector<int> arr;
std::vector<int> adj[7];
    adj[0] = {1, 2};
    adj[1] = {2, 3};
    adj[2] = {5};
    adj[3] = {0};
    adj[4] = {5};
    adj[5] = {};
int V=6;
vector<int> visited(V,0);
vector<int> path(V,0);
vector<int> check(V,0);
for(int i=0;i<V;i++){
    if(!visited[i]){
        DFS(adj, visited, path, check, i);
    }
}

vector<int> ans;
for(int i=0;i<V;i++){
  if(check[i]==1){
    ans.push_back(i);
  }
}
for(auto it :ans){
    cout<<it<<" ";
}
}