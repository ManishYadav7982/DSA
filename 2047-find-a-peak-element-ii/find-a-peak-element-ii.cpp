class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int rw[] = {0, -1, 0, 1};
                int cl[] = {-1, 0, 1, 0};
                bool flag = true;

                for (int k = 0; k < 4; k++) {
                    int new_row = i + rw[k];
                    int new_col = j + cl[k];
                    if (new_row >= 0 && new_row < n && new_col >= 0 &&
                        new_col < m && flag) {
                        if (mat[new_row][new_col] > mat[i][j]) {
                            flag = false;
                            // cout << " change flag to flase ";
                            break;
                        }
                    }
                }

                if (flag) {
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }

        return ans;
    }
};