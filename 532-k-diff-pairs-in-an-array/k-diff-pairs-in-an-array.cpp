class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        
        for (int i : nums)
            mp[i]++;
        
        int ans = 0;
        for (auto [i, freq] : mp) {
            if (k == 0) {
                if (freq > 1)
                    ans++;
            } 
            else {
                if (mp.count(i + k))
                    ans++;
            }
        }
        
        return ans;
    }
};