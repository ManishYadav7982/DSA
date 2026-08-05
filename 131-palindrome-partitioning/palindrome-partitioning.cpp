class Solution {
private:
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void backtrack(int start, const string& s, vector<string>& ds, vector<vector<string>>& ans) {
        if (start == s.size()) {
            ans.push_back(ds);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                ds.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, ds, ans);
                ds.pop_back(); // Backtrack
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        backtrack(0, s, ds, ans);
        return ans;
    }
};