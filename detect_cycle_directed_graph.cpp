#include<bits/stdc++.h>
using namespace std;
class Solution {
    
    private:
     bool DFS(vector<int> adj[], vector<int> &visited,vector<int> &path, int start ){
         visited[start]=1;
         path[start]=1;
         
         for(auto it : adj[start]){
             if(!visited[it]){
                 if(DFS(adj, visited, path, it)==true){
                     return true;
                 }
             }
                 else if(path[it]==1){
                     return true;
                 }
         }
         
         path[start]=0;
         return false;
         
     }
    
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> visited(V, 0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
            if(DFS(adj, visited, path, i)){
                return true;
            }
            }
        }
        
        return false;
    }
};