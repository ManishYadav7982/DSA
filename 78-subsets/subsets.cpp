class Solution {
    void f(vector<int>& nums , vector<vector<int>> &ans , vector<int>& ds, int ind ){
        if(ind == nums.size()){
            ans.push_back(ds) ;
            return ; 
        }

        ds.push_back(nums[ind]);
        f(nums , ans , ds , ind+1 );
        ds.pop_back() ;

        f(nums , ans , ds , ind+1 );

        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans ;
    vector<int > ds ;
    f(nums , ans , ds , 0 );
    return ans ;
    }
};