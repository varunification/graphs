#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<vector<int>>grid{
    {0,1,2},
    {0,1,2},
    {2,1,1}
    };

int n = grid.size();
int m = grid[0].size();
vector<vector<int>> visited(n, vector<int>(m,0));
queue<pair<pair<int,int>, int>> q;
int dx[]={-1,0,1,0};
int cntFresh=0;
int tm=0;
int cnt=0;
int dy[]={0, -1, 0, 1};
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(grid[i][j]==2){
            q.push({{i,j},0});
            visited[i][j]=2;

        }
         else {
            visited[i][j] = 0;
          }
          // count fresh oranges
          if (grid[i][j] == 1) cntFresh++;
        
    }
}

while(!q.empty()){
int r = q.front().first.first;
int c = q.front().first.second;
int t = q.front().second;
tm=max(t,tm);
q.pop();

for(int i=0;i<4;i++){

int nr=r+dx[i];
int nc=c+dy[i];
if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
            visited[nr][nc] == 0 && grid[nr][nc] == 1) {
            // push in queue with timer increased
             q.push({{nr, nc}, t + 1}); 
            // mark as rotten
            visited[nr][nc] = 2;
            cnt++;

}


}
}
cout<<cnt;

return 0;
}