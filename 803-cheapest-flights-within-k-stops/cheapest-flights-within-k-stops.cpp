class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto &e : flights) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];
            adj[u].push_back({v, wt});
        }

        // for(int i =0;i<n;i++){
        //     cout << i << "-> " ;
        //     for(auto ele : adj[i]){
        //         cout << ele.first << "\t" << ele.second ;
        //     }
        //     cout << endl ;
        // }

        queue<tuple<int, int, int>> q; // K , node , wt
        q.push({0, src, 0});
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty()) {
            auto [stops, curr, wt] = q.front();
            q.pop();
            if (stops > k)
                continue;
            for (auto& [nbd, edgw] : adj[curr]) {

                if (wt + edgw < dist[nbd] && stops <= k) {
                    dist[nbd] = wt + edgw;
                    q.push({stops + 1, nbd, wt + edgw});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};