class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;

        int ones = 0;
        string ans = "";

        while (r < n) {

            if (s[r] == '1') {
                ones++;
            }

            while (ones == k) {
                while (s[l] == '0') {
                    l++;
                }

                string curr_str = s.substr(l , r - l + 1);

                if (ans.empty() || curr_str.size() < ans.size() ||
                    (ans.size() == curr_str.size() && curr_str < ans)) { 
                    ans = curr_str;
                }

               
                ones-- ;
                l++;
            }
            r++ ;
        }

        return ans;
    }
};