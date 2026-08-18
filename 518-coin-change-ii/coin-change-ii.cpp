class Solution {

    private:
    int f(int ind, int amt, vector<int>& coins,vector<vector<int>> &dp) {
        if (ind == 0) {
            if (amt % coins[0] == 0)
                return 1;
            else
                return 0;
        }
        
        if(dp[ind][amt] != -1 ) return dp[ind][amt] ;

        int nottake = f(ind - 1, amt, coins ,dp);
        int take = 0;
        if (amt >= coins[ind]) {
            take =  f(ind, amt - coins[ind], coins ,dp);
        }

        return  dp[ind][amt] = take+ nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
         int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
         int ans = f(n-1 , amount,coins,dp ) ;
         return ans ;
    }
};