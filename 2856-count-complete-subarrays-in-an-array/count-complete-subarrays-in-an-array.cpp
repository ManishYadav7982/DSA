class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int > set ;
        for(int ele : nums ){
            set.insert(ele );
        }

        // for(int ele: set){
        //     cout << ele << ' ';
        // }
        int n = set.size();
        int cnt = 0  ; 

        for(int i = 0 ; i < nums.size() ;i++ ){
            unordered_set<int > sett ;
            for(int j = i ; j < nums.size() ; j++){
                sett.insert(nums[j]);
                if(sett.size() == n ) cnt++ ;
            }

        }

        return cnt  ;
        
    }
};