#include<bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>> &grid,vector<vector<int>> &visited, int row, int column){
queue<pair<int,int>> q;
q.push({row, column});
visited[row][column]=1;
int n = grid.size();
int m = grid[0].size();
while(!q.empty()){
int row=q.front().first;
int column=q.front().second;
q.pop();
for(int di=-1;di<=1;di++){
    for(int dj=-1;dj<=1;dj++){
        // if we do not want diagonal elements just add this line
if(di!=0 && dj!=0){
    continue;
}
        int newrow=row+di;
        int newcol=column+dj;
        if(newrow<n && newcol<m && newrow>=0 && newcol>=0 && visited[newrow][newcol]==0 && grid[newrow][newcol]==1 ){
            visited[newrow][newcol]=1;
            q.push({newrow,newcol});
        }
    }
}
}
}
int main()
{
vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 0, 0, 1, 1},
    };

int n = grid.size();
int m = grid[0].size();
vector<vector<int>>visited(n, vector<int>(m,0));
int count=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(visited[i][j]==0 && grid[i][j]==1){
            count++;
            BFS(grid, visited, i, j);
        }
    }
}
cout<<count;
 return 0;
}