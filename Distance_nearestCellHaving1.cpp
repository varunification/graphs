#include<bits/stdc++.h>
using namespace std;
int main()
{
    std::vector<std::vector<int>> binaryMatrix = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };
    int n = binaryMatrix.size();
    int m = binaryMatrix[0].size();
std::vector<std::vector<int>> distance(n, vector<int>(m,1e9));
std::vector<std::vector<int>> visited(n, vector<int>(m,0));
queue<pair<pair<int,int>,int>> q;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(binaryMatrix[i][j]==1){
       q.push({{i, j},0});
       visited[i][j]=1;
       distance[i][j]=0;
        }
    }
}
while(!q.empty()){
// explore
int row= q.front().first.first;
int column= q.front().first.second;
int d= q.front().second;
q.pop();
for(int di=-1;di<=1;di++){
    for(int dj=-1;dj<=1;dj++){
           if(di!=0 && dj!=0) continue;
int r=row+di;
int c= column+dj;
          if(r<n && r>=0 && c<m && c>=0 && visited[r][c]==0 && binaryMatrix[r][c]==0){
            visited[r][c]=1;
            distance[r][c]=d+1;
            q.push({{r,c},d+1});
          }
    }
}
}
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
 cout<<distance[i][j]<<" ";   
}
cout<<endl;
}
 return 0;
}