#include<bits/stdc++.h>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Direction arrays for the four cardinal directions
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        queue<pair<int, int>> rottenQueue;

        // Count of fresh oranges
        int freshCount = 0;

        // Initialize the rottenQueue and count the number of fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int minutes = 0;
        int rottenCount = rottenQueue.size();

        // Perform BFS starting from rotten oranges
        while (!rottenQueue.empty()) {
            if (rottenCount == 0) {
                rottenCount = rottenQueue.size();
                minutes++;
            }

            pair<int, int> curr = rottenQueue.front();
            rottenQueue.pop();
            rottenCount--;

            int currX = curr.first;
            int currY = curr.second;

            // Check all four directions
            for (int k = 0; k < 4; k++) {
                int newX = currX + dx[k];
                int newY = currY + dy[k];

                // Check if the new coordinates are valid and the orange is fresh
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                    grid[newX][newY] = 2; // Rot the fresh orange
                    freshCount--;
                    rottenQueue.push({newX, newY});
                }
            }
        }

        // If there are still fresh oranges, return -1; otherwise, return the number of minutes taken
        return (freshCount == 0) ? minutes : -1;
    }
};
