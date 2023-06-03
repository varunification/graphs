#include<bits/stdc++.h>

using namespace std;

void DFS(vector<vector<char>> &mat, vector<vector<int>> &visited, int row, int col, int dx[], int dy[], int n, int m) {
    visited[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && mat[nrow][ncol] == '0' && visited[nrow][ncol] == 0) {
            DFS(mat, visited, nrow, ncol, dx, dy, n, m);
        }
    }
}

int main() {
    vector<vector<char>> mat = {{'X', 'X', 'X', 'X'},
                                {'X', 'O', 'X', 'X'},
                                {'X', 'O', 'O', 'X'},
                                {'X', 'O', 'X', 'X'},
                                {'X', 'X', 'O', 'O'}};

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int dx[] = {0, 1, -1, 0};
    int dy[] = {1, 0, 0, -1};

    for (int i = 0; i < n; i++) {
        if (mat[i][0] == 'O' && !visited[i][0]) {
            DFS(mat, visited, i, 0, dx, dy, n, m);
        }
        if (mat[i][m - 1] == 'O' && !visited[i][m-1]) {
            DFS(mat, visited, i, m - 1, dx, dy, n, m);
        }
    }

    for (int j = 0; j < m; j++) {
        if (mat[0][j] == 'O' && !visited[0][j]) {
            DFS(mat, visited, 0, j, dx, dy, n, m);
        }
        if (mat[n - 1][j] == 'O' && !visited[n-1][j]) {
            DFS(mat, visited, n - 1, j, dx, dy, n, m);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]==0 && mat[i][j]=='O') {
                mat[i][j]='X';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
