class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // k = k % n
        int n = nums.size() ;
         k = k%n;
         reverse(nums.begin() , nums.end());
        int i = k ;
        int j = n-1;
        while(i <=j){
            swap(nums[i] ,nums[j]) ;
            i++ , j-- ;
        }
        
        int s =0;
        int l = k-1 ;
        while(s<= l){
            swap(nums[s] ,nums[l]);
            s++ ,l-- ;
        }
    }
};