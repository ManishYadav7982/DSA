class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ;
        
        int mx = -1e9 ;
        vector<int> mn(n , -1 ) ;
        int min =1e9 ;

        for(int i = n -1 ;i>= 0;i--){
            if(nums[i] < min){
                mn[i] = nums[i] ;
                min = nums[i] ;
            }
            else mn[i] = min ;
        }
        // for(int i : mn){
        //     cout << i <<' ' ; 
        // }

        for(int i=0;i<n;i++){
            mx = max(mx , nums[i]);
            if(mx - mn[i] <= k ) return i ;

        }

        return -1 ;

    }
};