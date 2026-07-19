class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    vis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        int dr[] = {0, -1, 0, 1};
        int dc[] = {-1, 0, 1, 0};
        while (q.size() > 0) {
            int rw = q.front().first ;
            int cl = q.front().second ;
            q.pop();

            for(int i = 0 ;i<4 ;i++){
                int new_row = rw + dr[i];
                int new_col = cl + dc[i];

                if(new_row >= 0 && new_row < n && new_col >=0 && new_col < m && vis[new_row][new_col] == -1  ){
                    vis[new_row][new_col] = vis[rw][cl] +1 ;
                    q.push({new_row , new_col});
                }
            }
        }

        return vis ;
    }
};