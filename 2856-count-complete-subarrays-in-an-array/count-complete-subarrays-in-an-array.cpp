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
        int dis_ele = set.size();
        unordered_map<int , int > mp;
        int n = nums.size();

        int l = 0 , r= 0 , cnt = 0 ;
        while(r < n ){
            mp[nums[r]]++ ;
            while(l <= r && mp.size() == dis_ele){
                cnt += n - r ; 
                mp[nums[l]]-- ;
                if(mp[nums[l]] == 0 ){
                    mp.erase(nums[l]);
                }
                l++ ;
            }
            r++ ;
        }

        return cnt  ;
        
    }
};