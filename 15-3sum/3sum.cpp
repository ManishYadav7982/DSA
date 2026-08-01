class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n= nums.size() ;
        vector<vector<int>> ans ;
        sort(nums.begin() , nums.end()) ;
        for(int i=0;i<n-1;i++){
            if(nums[i] > 0 ) break ;
            if(i > 0 && nums[i] == nums[i-1 ]) continue ;

            int l = i+1 ;
            int r = n- 1 ;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r] ;

                if(sum== 0 ){
                    vector<int > store = { nums[i] , nums[l] , nums[r]}; // order is imp becasue nums is sorted ;
                    l++ , r--;
                    ans.push_back(store);
                    while(l < n && nums[l] == nums[l-1]) l++ ; // move l until l value is same 
                    while(r < 0 && nums[r-1] == nums[r]) r-- ;// move r until r value is same 

                }
                else if(sum < 0 ) l++ ;
                else r-- ;
            }

        }

        return ans ;
        
    }
};