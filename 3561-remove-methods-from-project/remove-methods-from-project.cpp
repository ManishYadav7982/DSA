#include <vector>

using namespace std;

class Solution {
private:
    // DFS to mark all suspicious methods reachable from k
    void markSuspicious(int node, vector<vector<int>>& adj, vector<bool>& isSuspicious) {
        isSuspicious[node] = true;
        for (int neighbor : adj[node]) {
            if (!isSuspicious[neighbor]) {
                markSuspicious(neighbor, adj, isSuspicious);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for (const auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        // Step 1: Mark all methods reachable from 'k'
        vector<bool> isSuspicious(n, false);
        markSuspicious(k, adj, isSuspicious);

        // Step 2: Check for external calls (u is safe, v is suspicious)
        for (const auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            if (!isSuspicious[u] && isSuspicious[v]) {
                // Illegal to remove! Return ALL methods
                vector<int> allMethods(n);
                for (int i = 0; i < n; ++i) allMethods[i] = i;
                return allMethods;
            }
        }

        // Step 3: Collect only non-suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (!isSuspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};