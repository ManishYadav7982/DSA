class Solution {
    void f(vector<int>& nums , vector<vector<int>> &ans , vector<int>& ds, int ind ){
        if(ind == nums.size()){
            ans.push_back(ds) ;
            return ; 
        }


        // backtracking 
        ds.push_back(nums[ind]); // do somethings 
        f(nums , ans , ds , ind+1 ); // expore 
        ds.pop_back() ;// undo 

        f(nums , ans , ds , ind+1 ); // again expore in undo thing with +1 ind ; 

        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans ;
    vector<int > ds ;
    f(nums , ans , ds , 0 );
    return ans ;
    }
};