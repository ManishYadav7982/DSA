////
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for ( auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> minCost(n, 1e9);
        minCost[src] = 0;

        queue<pair<int, int>> q;
        q.push({src, 0});

        int stops = 0;
        while (!q.empty() && stops <= k) {
            int size = q.size();
            
            while (size--) {
                auto [node, cost] = q.front();
                q.pop();

                for (auto& [neighbor, price] : adj[node]) {
                    if (cost + price < minCost[neighbor]) {
                        minCost[neighbor] = cost + price;
                        q.push({neighbor, minCost[neighbor]});
                    }
                }
            }
            stops++;
        }

        return minCost[dst] == 1e9 ? -1 : minCost[dst];
    }
};