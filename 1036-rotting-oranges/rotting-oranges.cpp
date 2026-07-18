class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        queue<pair<pair<int , int > , int >> q ;
        vector<vector<int>> vis(n  ,vector <int> (m , 0 ));

        int cntfresh =  0;

        // first push which is already rotton at t = 0 ;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j] == 2 ){
                    q.push({{i , j},0}) ;
                    vis[i][j]=2 ;
                }
                else  if(grid[i][j] ==  1){
                    cntfresh++ ;
                }
            }
        }
        int maxtm = 0 ;
        int row[] = {0 , -1, 0 , 1};
            int col[] ={-1 , 0 ,+1 , 0 } ;
            int cnt=0;
        while(q.size() > 0 ){
            int r = q.front().first.first ;
            int c = q.front().first.second ;
            int t = q.front().second ;
        q.pop();
            maxtm = max(maxtm , t);

            for(int i=0;i<4;i++){
                int travlrow = r + row[i];
                int travlcol = c+col[i] ;

                if( travlrow >= 0 && travlrow< n && travlcol>=0 && travlcol< m && grid[travlrow][travlcol] == 1 && vis[travlrow][travlcol] != 2 ){
                    q.push({{travlrow , travlcol} , t+1  }) ;
                    vis[travlrow][travlcol] = 2 ;
                    cnt++ ; 
                }

            }




        }

        if(cnt != cntfresh ) return -1 ;
        else return maxtm ;



        
    }
};