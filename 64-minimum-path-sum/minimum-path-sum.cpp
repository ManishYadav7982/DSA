class Solution {
private:
    int f(int row, int col, vector<vector<int>>& grid ,vector<vector<int>> &dp) {
        if (row == 0 && col == 0) {
            return grid[row][col];
        }
        if(dp[row][col] != -1 ){
            return dp[row][col] ;
        }

        int up = INT_MAX, left = INT_MAX;
        if (row > 0) {
            up = grid[row][col] + f(row - 1,col, grid ,dp);
        }
        if (col > 0) {
            left = grid[row][col] + f(row, col - 1, grid,dp);
        }

        return dp[row][col] =  min(up, left);
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row ,vector<int> (col , -1 )) ; 
        return f(row - 1, col - 1, grid , dp );
    }
};