#include<bits/stdc++.h>
using namespace std;

bool BFS(vector<vector<int>> &grid, vector<int> &visited){
queue<pair<int,int>> q;
q.push({0, -1});
visited[0]=1;

while(!q.empty()){
    int ele= q.front().first;
    int parent=q.front().second;
    q.pop();
for(auto node: grid[ele]){
    if(visited[node]==true && node!=parent){
        return false;
    }
    else if(!visited[node]){
        visited[node]=1;
        q.push({node, ele});
    }
}
}
return true;
}
int main()
{
    // Add edges to the adjacency list
   vector<vector<int>> adjacencyList(5);
    // Add edges to the adjacency list
    adjacencyList[0].push_back(1);
    adjacencyList[1].push_back(0);
    adjacencyList[0].push_back(2);
    adjacencyList[2].push_back(0);
    adjacencyList[1].push_back(3);
    adjacencyList[3].push_back(1);
    adjacencyList[2].push_back(4);
    adjacencyList[4].push_back(2);
int n = adjacencyList.size();
vector<int> visited(n,0);
cout<<BFS(adjacencyList,visited);
return 0;
}