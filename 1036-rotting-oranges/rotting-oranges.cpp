class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m =grid[0].size() ;

        vector<vector<int >> vis = grid ;

        queue<tuple<int,int,int> > q ; // row , col , time 

        for(int i =0;i<n;i++){
            for(int j = 0 ;j<m;j++){
                if(grid[i][j] == 2 ){
                    q.push({i , j , 0  }) ;
                }
            }
        }
        int mx_time = 0 ;
        while(!q.empty()){
            auto [rw , cl , time ] = q.front() ;
            q.pop() ;
            mx_time = max(mx_time , time );
            int row[] = {0 , -1 , 0 , 1} ;
            int col[] = {-1 ,0 , 1 , 0 } ;

            for(int i=0;i<4;i++){
                int n_row = rw + row[i] ;
                int n_col = cl + col[i] ;

                if(n_row >= 0 && n_row < n && n_col >=0 && n_col < m && vis[n_row][n_col] == 1){
                    vis[n_row][n_col] = 2 ;
                    q.push({n_row , n_col , mx_time+1}) ;
                }
            }
        }


        for(int i = 0 ;i<n;i++){
            for(int j =0;j<m;j++){
                if(vis[i][j] == 1  ) return -1 ;
            }
        }

        return mx_time ;


        
    }
};