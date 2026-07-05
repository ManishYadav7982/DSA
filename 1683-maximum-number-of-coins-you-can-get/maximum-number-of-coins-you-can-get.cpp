////
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int n = piles.size();
        int ans = 0;
        int left = 0;
        int right = n - 1;

        while (left < right) {
            right--;              
            ans += piles[right];  
            right--;
            left++;           
        }

        return ans;
    }
};