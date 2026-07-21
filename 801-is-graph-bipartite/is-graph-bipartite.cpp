class Solution {
    private :
    bool dfs(int node, int currcolor ,vector<vector<int>>& graph , vector<int >& color ){
        color[node] = currcolor ;
        for(int neighbor  : graph[node ]){
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, !currcolor, graph, color)) {
                    return false;
                }
            } 
            else if (color[neighbor] == currcolor) {
                return false;
            }
        }

        return true ;
    }


public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int > color (n , -1 );

        for(int i = 0 ;i<n;i++){
             if(color[i] == -1){
                if(!dfs(i , 0 , graph , color)){
                    return false ;
                }
             }
        }

        return true ;
    }
};