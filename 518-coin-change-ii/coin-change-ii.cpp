class Solution {
private:
    int f(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if (amount == 0)
            return 1;

        if (ind == coins.size() || amount < 0)
            return 0;

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int take = 0;
        if (coins[ind] <= amount) {
            take = f(ind, amount - coins[ind], coins, dp);
        }
        int skip = f(ind + 1, amount, coins, dp);

        return dp[ind][amount] = take + skip;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(0, amount, coins, dp);
    }
};