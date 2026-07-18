class Solution {
    private :
    void dfs(vector<vector<int>>& isConnected , vector<int> &vis , int node){
        vis[node] = 1;

        for(int i = 0 ;i<isConnected.size() ;i++){
            if(isConnected[node][i] == 1 && vis[i] != 1 ){
                dfs(isConnected , vis , i);
            }
        }

    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n , 0 );

        int cnt = 0 ;
        for(int i =0 ;i<n;i++){
            if(!vis[i]){
                cnt++ ;
                dfs(isConnected , vis , i ) ;
            }
        }


        return cnt ;

        
    }
};