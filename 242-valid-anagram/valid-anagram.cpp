class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        if(s.size() != t.size()) return false ;

        for (auto i : s) {
            mp[i]++;
        }

        for (auto i : t) {
            if (mp.find(i) != mp.end()) {
                mp[i]--;
                if (mp[i] == 0) {
                    mp.erase(i);
                }
            }
            else {
                return false;
            }
        }

        return true;
    }
};