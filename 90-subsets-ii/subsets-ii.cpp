class Solution {
private:
    void f(vector<int>& nums, set<vector<int>>& sett, vector<int>& ds,
           int ind) {
        if (ind == nums.size()) {
            sett.insert(ds);
            return;
        }

        // backtracking
        ds.push_back(nums[ind]);   // do somethings
        f(nums, sett, ds, ind + 1); // expore
        ds.pop_back();             // undo

        f(nums, sett, ds, ind + 1); // again expore in undo thing with +1 ind ;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        set<vector<int>> sett;
        vector<int> ds;
        f(nums, sett, ds, 0);
        
         vector<vector<int>> ans ; 
        for(auto i : sett){
            ans.push_back(i);
        }
       
        return ans ; 
    }
};