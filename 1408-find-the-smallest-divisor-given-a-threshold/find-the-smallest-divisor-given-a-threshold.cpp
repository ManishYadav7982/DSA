class Solution {
    bool check(vector<int> nums, int t , int mid ){
        int div = mid ;
        long long  cnt = 0 ;
        for(int i : nums){
            if(i % div != 0 ){
                cnt++;
            }
            cnt += i / div ;
            // cout << cnt  <<" " ;
        }
        // cout << endl ;

        return t >= cnt ;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int h = *max_element(nums.begin() , nums.end());
        int ans = h ;
        while(l <= h){
            int mid = l+(h-l)/2 ;
            if(check(nums , threshold , mid )){
                ans = mid ;
                h = mid -1 ;
            }
            else l = mid +1;
        }

        return ans ;

        
    }
};