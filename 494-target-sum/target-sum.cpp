class Solution {
    int f(int ind, int sum, vector<int>& nums, int& target) {
        if (ind >= nums.size() && sum != target) {
            return 0;
        } else if (ind == nums.size() && sum == target) {
            return 1;
        }
        // else if(ind >= nums.size() && sum != target){
        //     return 0 ;
        // }
        int r = f(ind + 1, sum - nums[ind] - nums[ind] , nums, target);

        int l = f(ind + 1, sum, nums, target);
        // int r = f(ind + 1, sum - nums[ind], nums, target);

        return r + l;
    }
    // int f(int ind , int sum ,vector<int>& nums, int target ){
    //     if(ind <= nums.size() && sum == target ){
    //         return 1;
    //     }
    //     if(ind > nums.size()){
    //         return 0 ;
    //     }

    //     int l = f(ind+1 , sum + nums[ind], nums , target);
    //     int r=f(ind+1 ,sum-nums[ind],nums,target) ;

    //     return l+r ;
    // }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long long sum = 0;
        for (int i : nums)
            sum += i;
        cout << sum << endl;

        return f(0, sum, nums, target);
    }
};