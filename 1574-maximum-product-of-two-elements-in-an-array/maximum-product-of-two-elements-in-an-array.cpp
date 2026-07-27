class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;

        int first = nums[n-1] -1 ;
        int sec = nums[n-2] -1 ;
        return first*sec ;
        // priority_queue<int > pq ;

        // pq.push(nums[0]) ;
        // while(!pq.empty()){

        //     int size = pq.size() ;
        //     while(size >= 2 ){
        //         ans.push_back(pq.top());
        //     }
        // }
        
    }
};