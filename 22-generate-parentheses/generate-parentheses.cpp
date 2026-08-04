class Solution {
private:
    // bool isValid(string& curr) {
    //     int cnt = 0;
    //     for (auto i : curr) {
    //         if (i == '(')
    //             cnt++;
    //         else
    //             cnt--;

    //         if (cnt < 0)
    //             return false;
    //     }

    //     return cnt == 0;
    // }

    void made(vector<string>& ans, string& curr, int n, int open, int close) {
        if ((int)curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // backtracking
        // do someting then expore then again apply updo
        if (open < n) {
            curr.push_back('(');
            made(ans, curr, n, open + 1, close);
            curr.pop_back();
        }
        if (close < open) {
            curr.push_back(')');
            made(ans, curr, n, open, close +1);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        made(ans, curr, n, 0, 0);
        return ans;
    }
};