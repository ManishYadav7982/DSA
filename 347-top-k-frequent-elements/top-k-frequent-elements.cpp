class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size() ;
        priority_queue<pair<int,int >> pq ;
        unordered_map<int ,int > mp ;

        for(int i=0;i<n;i++){
            mp[nums[i]] ++ ;
        }

        for(auto & [key , value] : mp){
            pq.push({value , key });
        }
        vector<int > ans;

        while(k){
            auto [fq , key]= pq.top();
            pq.pop();
            ans.push_back(key) ;
            k-- ;

        }

        return ans ;
    }
};