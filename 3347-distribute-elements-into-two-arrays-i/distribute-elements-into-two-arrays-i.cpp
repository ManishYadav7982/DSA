class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size() ;

        vector<int > first , sec ;

        first.push_back(nums[0]) ;
        sec.push_back(nums[1]) ;
        // sec.push_back(100) ;

        for(int i=2 ;i<n;i++){
           if(first.back() > sec.back()){
            first.push_back(nums[i]) ;
           }
           else sec.push_back(nums[i]) ;
        }


        for(int ele : sec){
            first.push_back(ele) ;
        }



        
        return first  ;
        
    }
};