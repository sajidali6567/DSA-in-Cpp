class Solution {
public:
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        // Base case
        if(j1 <0 || j2 < 0 || j1 >= grid[i].size() || j2 >= grid[i].size()) {
            return -1e9;
        }
        // reaches the destination
        if(i == grid.size()-1)  {
            if(j1 == j2) {
               return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int maxi = -1e9;
        // Explore all the possibilities
        // alice's path
        for(int dj1=-1;dj1<=1;dj1++) {
            for(int dj2=-1;dj2<=1;dj2++) {
                int value;
                if(j1 == j2) {
                    value = grid[i][j1];
                } else {
                    value = grid[i][j1] + grid[i][j2];
                }
                value += f(i+1, j1+dj1, j2+dj2, grid, dp);
                maxi = max(maxi,value);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        if(grid.size() == 0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return f(0, 0, grid[0].size()-1, grid, dp);
    }
};