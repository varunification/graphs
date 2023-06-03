//{ Driver Code Starts
// Initial Template for C++
#include<bits/stdc++.h> 
using namespace std;
// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    void DFS(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int,int>> &vec, int row0, int col0){
        visited[row][col]=1;
        vec.push_back({
        row - row0,
        col - col0
      });
        int n = grid.size();
        int m = grid[0].size();
         int dx[] = {-1, 0, +1, 0}; 
         int dy[] = {0, -1, 0, +1}; 
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                  DFS(nrow,ncol,grid,visited,vec,row0,col0);
            }  
            }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
       // distict use set data structure
       set<vector<pair<int,int>>> st;
       int n=grid.size();
       int m=grid[0].size();
       vector<vector<int>> visited(n,vector<int>(m,0));
       
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               
               if(grid[i][j]==1 && !visited[i][j]){
                   vector<pair<int,int>> temp;
                   DFS(i,j,grid,visited, temp,i,j);
                   st.insert(temp);
               }
           }
       }
       return st.size();
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid={{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}};
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends