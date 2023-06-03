#include<bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> &mat, vector<vector<int>> &visited, int row, int col, int dx[], int dy[], int n, int m) {
    visited[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && mat[nrow][ncol] == 1 && visited[nrow][ncol] == 0) {
            DFS(mat, visited, nrow, ncol, dx, dy, n, m);
        }
    }
}
int main()
{
 vector<vector<int>> mat = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}};

int n = mat.size();
int m = mat[0].size();
vector<vector<int>> visited(n, vector<int>(m,0));


int dx[] = {0, 1, -1, 0};
    int dy[] = {1, 0, 0, -1};

    for (int i = 0; i < n; i++) {
        if (mat[i][0] == 1 && !visited[i][0]) {
            DFS(mat, visited, i, 0, dx, dy, n, m);
        }
        if (mat[i][m - 1] == 1 && !visited[i][m-1]) {
            DFS(mat, visited, i, m - 1, dx, dy, n, m);
        }
    }

    for (int j = 0; j < m; j++) {
        if (mat[0][j] == 1 && !visited[0][j]) {
            DFS(mat, visited, 0, j, dx, dy, n, m);
        }
        if (mat[n - 1][j] == 1 && !visited[n-1][j]) {
            DFS(mat, visited, n - 1, j, dx, dy, n, m);
        }
    }
int count=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]==0 && mat[i][j]==1) {
                count++;
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << mat[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
      cout<<count;
    return 0;

}