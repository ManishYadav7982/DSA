class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> outdegree(n, 0);

        for (int i = 0; i < n; i++) {
            outdegree[i] = graph[i].size();
            for (auto  j : graph[i]) {
                revGraph[j].push_back(i);
            }
        }


        // for(int i =0;i<n;i++){
        //     cout << i << "-> "; 
        //      for (auto  j : revGraph[i]) {
        //         cout <<j << "  " ; 
        //     }

        //     cout << endl ; 
        // }

        // for(auto i : outdegree){
        //     cout << i << "\t" ; 

        // }


        queue<int > q ;
        
        for(int i=0;i<n;i++){
            if(outdegree[i] == 0 ){ // termination node 
                q.push(i);
            }
        }

        vector<bool > safenode(n , false );
        while(!q.empty()){
            int node= q.front();
            q.pop();
            safenode[node] = true ;

            for(auto nbd : revGraph[node]){
                outdegree[nbd]-- ;
                if(outdegree[nbd] == 0) q.push(nbd );
            }

        }

        vector<int> ans ;
        for(int i =0 ;i<n;i++){
            if(safenode[i]) ans.push_back(i);
        }

        return ans ;
    }
};