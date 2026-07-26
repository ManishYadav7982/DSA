class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n+1 );
        for (const auto &e : times) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({wt, v}) ;// src  = {wt , dest} ;
        }

        priority_queue<tuple<int, int, int>,   
                        vector<tuple<int, int, int>>,
                        greater<tuple<int, int, int>>>q ;  // time , startingnode ,targetnode 

        vector<int> dist(n +1 , 1e9) ;
        dist[0] = -1 ;

        q.push({0,k,k}) ;
        dist[k] = 0 ;

        while(!q.empty()){
            auto [currwt , src , dst] = q.top() ;
            q.pop() ;

            if(dist[dst] < currwt) continue ;

            for(auto &ele : adj[dst]){ // travel on nbd of dst node 
                auto [nbd_wt , nbd] = ele ;
                if(nbd_wt + currwt < dist[nbd]){
                    dist[nbd] = nbd_wt + currwt ;
                    q.push({nbd_wt + currwt , src , nbd}) ;
                }


            }

        }

        int  mx = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9) return -1;
            mx = max(mx, dist[i]);
        }

        return mx;


          
    }
};