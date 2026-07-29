class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));

        queue<pair<int, int>> q;
        q.push({sr, sc});
        int isInialColor = image[sr][sc];
        vis[sr][sc] = color;

        while (!q.empty()) {
            auto [rw, cl] = q.front();
            q.pop();

            int row[] = {0, -1, 0, 1};
            int col[] = {-1, 0, 1, 0};

            for (int i = 0; i < 4; i++) {
                int n_row = rw + row[i];
                int n_col = cl + col[i];

                if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m &&
                    image[n_row][n_col] == isInialColor &&
                    vis[n_row][n_col] == -1) {
                    vis[n_row][n_col] = color;
                    q.push({n_row, n_col});
                }
            }
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << vis[i][j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] != color) {
                vis[i][j] = image[i][j];
            }
        }
    }

    return vis;
}
}
;