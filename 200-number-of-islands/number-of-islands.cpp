class Solution {
    private :
    void dfs(vector<vector<char>>& board , vector<vector<int>> &vis , int row , int col , int  n , int m ){
            vis[row][col] = -1 ;

            int dr[]  = {0 , -1 , 0 , 1 };
            int dc[] = { -1 , 0 , +1 , 0 };

            for(int i = 0 ;i<4;i++ ){
                int newr = row + dr[i] ;
                int newc = col + dc[i] ;
                if( newr >= 0 && newr < n && newc >= 0 && newc < m && board[newr][newc] == '1' && vis[newr][newc] != -1){
                    vis[newr][newc] =-1 ;
                    dfs(board ,vis ,  newr , newc , n , m ) ;
                }
            }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int >> vis(n , vector<int> (m , 0 ));
        int cnt = 0 ;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == '1' && vis[i][j] != -1 ){
                    dfs(grid , vis , i , j , n , m );
                    cnt++ ;
                }
            }
        }

        return cnt ;

        
    }
};