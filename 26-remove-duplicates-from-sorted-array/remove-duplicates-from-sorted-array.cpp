class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        set<int > mp ;
        for(int i = 0 ; i<n;i++){
            mp.insert(nums[i]);
        }

        int ind = 0;
        for (auto i : mp) {
            nums[ind] = i;
            ind++;
        }
        
        
        return mp.size();
    }
};