class Solution {
    using ll = long long ;
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size() ;

        ll mx_sum = -1e9 ;
        ll sum =0 ;

        for(int i=0;i<n;i++){
            sum += nums[i] ;
            if(sum < 0 ){
                sum = 0 ;
            }
            mx_sum = max(sum , mx_sum ) ;
        }

        if(mx_sum == 0 ){
            mx_sum = *max_element(nums.begin() , nums.end());
        }

        return mx_sum ;
    }
};