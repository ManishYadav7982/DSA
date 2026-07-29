class Solution {
    void bfs(int row , int col , vector<vector<int> >& vis ,vector<vector<char>>& board , int n , int m  ){
        queue<pair<int ,int >> q ;
        q.push({row , col });
        vis[row][col] =1 ;
      

        while(!q.empty()){
            auto [rw , cl ] = q.front();
            q.pop();

            int row[] = {0 , -1 , 0 , 1} ;
            int col[] = {-1 ,0 , 1 , 0 } ;

            for(int i=0;i<4;i++){
                int n_row = rw + row[i] ;
                int n_col = cl + col[i] ;

                if(n_row >= 0 && n_row < n && n_col >=0 && n_col < m && vis[n_row][n_col] == 0 && board[n_row][n_col] == 'O'){
                    vis[n_row][n_col] =1 ;
                    q.push({n_row , n_col});
                    
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int  n = board.size();
        int m=board[0].size();
        vector<vector<int> > vis(n , vector<int> (m , 0 ));

        for(int col =0;col < m ;col++){
            if(board[0][col] == 'O' && !vis[0][col]) {
                bfs(0 , col , vis , board ,n , m  );
            }
            if(board[n-1][col] == 'O' && !vis[n-1][col]) {
                bfs(n-1, col , vis , board , n , m );
            }
        }

        for(int row =0;row < n ;row++){
            if(board[row][0] == 'O' && !vis[row][0]) {
                bfs(row, 0 ,vis , board, n , m  );
            }
            if(board[row][m-1] == 'O' && !vis[row][m-1]) {
                bfs(row , m-1, vis , board ,n,m );
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 'O' && vis[i][j] == 0 ){
                    board[i][j] = 'X';
                }
            }
        }

        
    }
};