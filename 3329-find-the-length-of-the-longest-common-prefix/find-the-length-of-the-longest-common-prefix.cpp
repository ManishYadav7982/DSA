class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<string> mp;

        for (auto ele : arr2) {
            string s = to_string(ele);
            string temp = "";
            for (auto i : s) {
                temp += i;
                mp.insert(temp);
            }
        }
        int maxlen = 0;
        for (auto ele : arr1) {
            string s = to_string(ele); // travel on arr1 ;
            string temp = "";

            for (auto i : s) { // travel on s
            temp+= i ;
                int len = 0;
                if (mp.find(temp) != mp.end()) {
                    len = temp.size();
                }
                 maxlen = max(len, maxlen);
            }

        }

        return maxlen;
    }
};