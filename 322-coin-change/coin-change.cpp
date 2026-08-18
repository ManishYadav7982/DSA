class Solution {
    private :
    int f(int ind , int amt ,vector<int>& coins, vector<vector<int>> & dp ){
        if(ind == 0 ){
            if (amt % coins[0] == 0)
                return amt / coins[0];
            else return 1e9 ;
        }
        if(dp[ind][amt] != -1) return dp[ind][amt] ;

        int nottake = f(ind-1 , amt,coins ,dp);
        int take = INT_MAX ;
        if(amt >= coins[ind]){
           take = 1 + f(ind , amt - coins[ind] , coins ,dp );
        } 

        return dp[ind][amt] = min(take , nottake ) ;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        vector<vector<int>> dp(n  ,vector<int> (amount +1 , -1 )) ;
        int ans = f(n-1 , amount ,coins,dp ) ;
        if (ans >= 1e9) {
            return -1;
        } else {
            return ans;
        }

    }
};