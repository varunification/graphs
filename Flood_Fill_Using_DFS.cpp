#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&ans,
     vector<vector<int>>& image, int newColor,
     int iniColor) {
        // color with new color
        ans[row][col] = newColor; 
        int n = image.size();
        int m = image[0].size(); 
        // there are exactly 4 neighbours
        for(int di=-1;di<=1;di++){

        for(int dj=-1;dj<=1;dj++){

            if(di!=0 && dj!=0) continue;
            // check for valid coordinate 
            // then check for same initial color and unvisited pixel
            int nrow=row+di;
            int ncol=col+dj;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
            image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, iniColor); 
            }
        }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, 
    int sr, int sc, int newColor) {
        // get initial color
        int iniColor = image[sr][sc]; 
        vector<vector<int>> ans = image; 
        // delta row and delta column for neighbours
     
        dfs(sr, sc, ans, image, newColor, iniColor); 
        return ans; 
    }
};

int main(){
		
	vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
// sr = 1, sc = 1, newColor = 2  	
	Solution obj;
	vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}