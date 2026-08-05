class Solution {
    private :
    void dfs(int node , vector<vector<int>> &adj  , vector<int> &vis ){
        vis[node] =1 ;

        for(auto & nbd : adj[node]){
            if(!vis[nbd]){
                dfs(nbd ,adj , vis ) ; 
            }
        }
    }

    void dffs(int node , vector<vector<int>> &adj  , vector<int> &vis , vector<int>&ans){
        vis[node] = -1 ;
        ans.push_back(node);
        for(auto &nbd : adj[node]){
            if(vis[nbd] ==0 ){
                dffs(nbd , adj , vis , ans );
            }
        }





    }
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        int size = invocations.size();
        vector<vector<int>> adj(n);

        vector<int> vis(n , 0 );

        for (auto e : invocations) {
            int u = e[0];
            int v = e[1];
            // if(u == k ){
            //     adj[u].push_back(v);
            //     adj[v].push_back(u);

            // }
             adj[u].push_back(v);
            // Indeg[v]++;
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j : adj[i]) {
        //         cout << j << ' ';
        //     }
        //     cout << endl;
        // }

        // cout << endl << endl;
        

        dfs(k ,adj ,vis  );

        // for (int i : vis) {
        //     cout << i << ' ';
        // }

        for (auto e : invocations) {
            int u = e[0];
            int v = e[1];
            if (vis[u] != 1 && vis[v] == 1) {
                vector<int> allMethods;
                for (int i = 0; i < n; i++) allMethods.push_back(i);
                return allMethods;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dffs(i, adj, vis, ans);
            }
        }

        // queue<int> q;

        // for (int i = 0; i < n; i++) {
        //     if (Indeg[i] == 0) {
        //         q.push(i);
        //     }
        // }
        // vector<int> ans;

        // while (!q.empty()) {
        //     int node = q.top();
        //     q.pop();
        //     // ans.push_back(node) ;
        //     for (auto& nbd : adj[node]) {
        //         ans.push_back(node) ;
        //         Indeg[nbd]-- ;
        //         if(Indeg[nbd] == 0 ){
        //             q.push(nbd) ;
        //         }

        //     }
        // }

        return ans;
    }
};