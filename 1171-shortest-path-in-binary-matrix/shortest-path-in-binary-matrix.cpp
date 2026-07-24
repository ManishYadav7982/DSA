class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
          int n = mat.size();
        int m = mat[0].size();
         int src[] ={0 , 0 } ;
         int dest[] = {n-1 , m-1 } ;
        // Edge check: Blocked source/destination
        if (mat[src[0]][src[1]] == 1 || mat[dest[0]][dest[1]] == 1) return -1;
        
        // Edge check: Source is already destination
        // cout << src[0] << dest[0] << src[1] << dest[1] ; 
        if (src[0] == dest[0] && src[1] == dest[1]) return 1;
        vector<vector<int>> vis(n , vector<int > (m , 1e9));
        
        vis[src[0]][src[1]] = 1;
        queue<pair<int , pair<int , int >>> q ;
        q.push(  {0 , {src[0] , src[1]}  } ) ;
        
        
        while(!q.empty()){
            
            int   dis = q.front().first ;
            auto [r , c ] = q.front().second ;
            q.pop() ;
            
            int row[] = {0 , -1 , 0 , 1 ,-1, -1 , 1 , 1 } ;
            int col[] = {-1 , 0 , 1 , 0 ,-1, 1 , 1 , -1 } ;
            // cout << "dist " << dist  << endl ;
            // cout << r << "   " << c << endl ;
        //   cout << vis[r][c] + 10 << endl ;
        //   vis[0][1] = vis[r][c] + 10 ;
        //   cout << vis[0][1] << endl ;
        
        
            for(int i=0;i<8;i++){
                int nrow = r +row[i] ;
                int ncol = c + col[i] ;
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                mat[nrow][ncol] == 0 && vis[nrow][ncol] == 1e9 ){
                
                    vis[nrow][ncol] = vis[r][c] + 1  ;
                    // cout << vis[nrow][ncol] << endl ;
                    if(nrow == dest[0] && ncol == dest[1]) return vis[nrow][ncol] ;
                    q.push({ vis[nrow][ncol]  , {nrow , ncol}}) ;
                }
            }
            
            
        }
        
        
        return -1 ;
        
    }
};