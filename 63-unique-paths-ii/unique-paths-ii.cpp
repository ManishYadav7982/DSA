class Solution {
    private:
    int f(int row, int col ,vector<vector<int>>& dp ,vector<vector<int>>& obstacleGrid) {
        if (row == 0 && col == 0 && obstacleGrid[row][col] ==0 ) {
            return 1;
        }
        if(dp[row][col] != -1 ) return dp[row][col] ; 
        int up = 0 , down = 0 ;  
        if (row > 0 && obstacleGrid[row][col] ==0 ) {
             up =  f(row - 1, col ,dp ,obstacleGrid);
        }
        if (col > 0 &&obstacleGrid[row][col] ==0  )
             down = f(row, col - 1,dp , obstacleGrid);
        return dp[row][col] = up + down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() ; // row 
        int n = obstacleGrid[0].size() ; // col 
        // if(m == 1 && n ==1 ) return 1 ; 
         vector<vector<int>> dp(m+1 , vector<int> (n+1 , -1 ));
         return f(m - 1, n - 1 , dp , obstacleGrid);

    }
};