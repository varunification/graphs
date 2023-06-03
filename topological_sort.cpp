#include<bits/stdc++.h>
class Solution
{
    private:
    void DFS(vector<int> adj[], vector<int> &visited, stack<int> &st, int node){
        visited[node]=1;
        for(auto adjnodes: adj[node]){
            if(!visited[adjnodes]){
                DFS(adj,visited,st,adjnodes);
            }
        }
        
        st.push(node);
        
    }
	public:
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>visited(V, 0);
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            DFS(adj, visited, st, i);
	        }
	    }
	    
	    
	    std::vector<int> ans(st.size());
        int i=0;
        while(!st.empty()){
            ans[i++]=(st.top());
            st.pop();
        }
	    return ans;
	    
	}
};