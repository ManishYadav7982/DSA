class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;

        int n = isConnected.size();
        vector<int> vis(n, 0);

        for (int it = 0; it < n; it++) {

            if (!vis[it]) {
                cnt++ ;
                queue<int> q;
                q.push(it);
                vis[it] = 1;
                while (q.size() > 0) {
                    int temp = q.front();
                    q.pop();

                    for (int i = 0; i < n; i++) {
                        if (isConnected[temp][i] == 1 && vis[i] != 1) {
                            vis[i] = 1;
                            q.push(i);
                        }
                    }

                    
                }
            }
        }

        return cnt;
    }
};