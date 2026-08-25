class Solution {

private:
    int Checkpalind(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            ans += Checkpalind(s, i, i); // check odd

            ans += Checkpalind(s, i, i + 1); // check even
        }
        return ans;
    }
};