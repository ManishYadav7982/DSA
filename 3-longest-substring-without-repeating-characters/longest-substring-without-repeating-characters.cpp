class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char  , int > mpp ;

        int l = 0 , r= 0 , max_len = 0 ;
        while(r < n ){
            mpp[s[r]]++;
            while( l < r &&   mpp[s[r]] > 1 ){
                mpp[s[l]]-- ;
                l++ ;
            }

            max_len = max(max_len , r - l + 1 );
            r++ ;
        }
        
        return max_len ;
    }
};