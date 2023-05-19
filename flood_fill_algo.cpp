/*Given a 2D screen arr[][] where each arr[i][j] is an integer 
representing the color of that pixel, also given the location of a pixel (X, Y) and a color C, 
the task is to replace the color of the given pixel and all the adjacent same-colored pixels 
with the given color.*/

#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int row, int col, int clr){

queue<pair<int,int>> q;
int n = grid.size();
int m = grid[0].size();
visited[row][col]=1;
q.push({row, col});
grid[row][col]=clr;
while(!q.empty()){
    int r=q.front().first;
    int c= q.front().second;
q.pop();
for(int di=-1;di<=1;di++){
    for(int dj=-1;dj<=1;dj++){
 int nr=r+di;
 int nc=c+dj;
     if(nr<n && nr>=0 && nc<m && nc>=0 && grid[nr][nc]==1 && visited[nr][nc]==0){
        visited[nr][nc]=1;
        grid[nr][nc]=clr;
        q.push({nr,nc});
     }


    }
}
}
}
int main()
{
vector<vector<int>> grid = {
{1, 1, 1, 1, 1, 1, 1, 1}, 
{1, 1, 1, 1, 1, 1, 0, 0}, 
{1, 0, 0, 1, 1, 0, 1, 1}, 
{1, 2, 2, 2, 2, 0, 1, 0}, 
{1, 1, 1, 2, 2, 0, 1, 0}, 
{1, 1, 1, 2, 2, 2, 2, 0}, 
{1, 1, 1, 1, 1, 2, 1, 1}, 
{1, 1, 1, 1, 1, 2, 2, 1}};
int x= 1;
int y = 1;
 int n = grid.size();
 int m = grid[0].size();
int c= 3;
vector<vector<int>> visited(n, vector<int>(m,0));

bfs(grid, visited, x,y, c);
for(auto row :grid){
    for(auto col: row){
        cout<<" "<<col;
    }
    cout<<"\n";
 }
 return 0;
}