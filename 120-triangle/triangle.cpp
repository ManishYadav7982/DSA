class Solution {
private:
    int f(int row, int col, vector<vector<int>>& triangle,
          vector<vector<int>>& dp) {
        if (row == triangle.size() - 1) {
            return triangle[row][col];
        }

        if (dp[row][col] != INT_MIN) {
            return dp[row][col];
        }

        int i = triangle[row][col] + f(row + 1, col, triangle, dp);
        // int iplus1 = INT_MAX ;
        // if(col <= triangle[row+1].size()-1){

        int iplus1 = triangle[row][col] + f(row + 1, col + 1, triangle, dp);
        //}

        return dp[row][col] = min(i, iplus1);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); // size of row
        int m = triangle[n - 1].size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return f(0, 0, triangle, dp);

        // for(int row = 0 ;row< n ;row++){
        //     for(int col = 0;col < triangle[row].size() ;col++){
        //         int
        //     }
        // }
    }
};