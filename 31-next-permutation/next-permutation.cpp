class Solution {
    private :
     void swapp(vector<int>& ans, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>& q, int index) {
        while(!q.empty()){
            auto top_pair = q.top();
            int new_ele = top_pair.first;
            int ind = -top_pair.second;
            q.pop();

            if(new_ele > ans[index]){
                swap(ans[index], ans[ind]);
                return;
            }
        }
    }

public:
    void nextPermutation(vector<int>& ans) {
        int n = ans.size(); 
        if (n <= 1) return;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

        int i = n - 2;

        while (i >= 0) {
            q.push({ans[i + 1], -(i + 1 ) });

            if (ans[i] < ans[i + 1]) {
                swapp(ans, q, i);
                reverse(ans.begin() + i + 1, ans.end());
                return; 
            }
            i--;
        }
        reverse(ans.begin(), ans.end());
        
    }
};