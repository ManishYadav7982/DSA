class Solution {
public:
    int countCommas(int n) {
        int ans = n - 1000 +1 ;
        if(ans < 0 ) ans = 0 ;
        return ans ;
        
    }
};