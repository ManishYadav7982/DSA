class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9 + 7;
        
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        //distance, node
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [curr_wt, curr_node] = pq.top();
            pq.pop();

            if (curr_wt > dist[curr_node]) continue;

            for (auto& edge : adj[curr_node]) {
                int nbd = edge.first;
                int edge_wt = edge.second;

                // Case 1: Found a strictly shorter path to nbd
                if (curr_wt + edge_wt < dist[nbd]) {
                    dist[nbd] = curr_wt + edge_wt;
                    ways[nbd] = ways[curr_node];
                    pq.push({dist[nbd], nbd});
                } 
                // Case 2: Found an additional shortest path to nbd
                else if (curr_wt + edge_wt == dist[nbd]) {
                    ways[nbd] = (ways[nbd] + ways[curr_node]) % MOD;
                }
            }
        }

        // for(auto ele : ways){
        //     cout << ele << " " ;
        // }

        return ways[n - 1];
    }
};