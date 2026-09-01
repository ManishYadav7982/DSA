class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;
        unordered_set<int> mp;

        for (int i = 0; i < n; i++) {
            mpp[s[i]]++;
        }
        int ans = 0;

        for (auto ele : mpp) {
            char key = ele.first;
            int val = ele.second;

            while (mp.find(val) != mp.end()) {
                if(val == 0 ) break ;
                ans++;
                val--;
            }

            mp.insert(val);
        }

        return ans ;
    }
};