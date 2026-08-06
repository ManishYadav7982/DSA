class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size() ;
        vector<int > nextGreaterElementt(n , 0 ) ;
        stack<int> s ; 
        for(int i = nums2.size()-1 ; i>=0 ; i--){
            while(s.size() > 0 && s.top() <= nums2[i]){
                s.pop();
            }
            if(s.empty()){
                nextGreaterElementt[i] = -1;
            }else{
                nextGreaterElementt[i] = s.top();

            }

            s.push(nums2[i]);

        }

        for(int i : nextGreaterElementt){
            cout << i << ' ' ; 
        }

        unordered_map<int ,int > mp ;
        for(int i=0;i<n;i++){
            int key = nums2[i];
            mp[key] = nextGreaterElementt[i];
        }

        vector<int> ans ;

        for(int i : nums1){
            ans.push_back(mp[i]);
        }


        return ans  ; 
        
    
    }
};