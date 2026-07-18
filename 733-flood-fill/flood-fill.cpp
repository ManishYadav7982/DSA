class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis = image;

        queue<pair<int, int>> q;
        int target = image[sr][sc];
        q.push({sr, sc});
        vis[sr][sc] = color;

        while (q.size() > 0) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int rw[] = {0, -1, 0, 1};
            int cl[] = {-1, 0, 1, 0};
            for (int i = 0; i < 4; i++) {
                int row = r + rw[i];
                int col = c + cl[i];
                if (row >= 0 && row < n && col >= 0 && col < m &&
                    image[row][col] == target && vis[row][col] != color) {
                    vis[row][col] = color;
                    q.push({row, col});
                }
            }
        }

        return vis;
    }
};