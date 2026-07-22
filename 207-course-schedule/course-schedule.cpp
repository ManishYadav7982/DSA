class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int > indegree(numCourses , 0 );

        for(auto e:prerequisites ){
            int course  = e[0];
            int prereq = e[1];
            adj[prereq].push_back(course);
            indegree[course]++ ;
        }

        queue<int>  q ;
        int complete_course = 0 ;
        for(int i = 0 ;i< numCourses ;i++){
            if(indegree[i] == 0){
                q.push(i);
                
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            complete_course++ ;

            for(auto nbd : adj[curr]){
                indegree[nbd]--;
                if(indegree[nbd] == 0 ){
                    q.push(nbd);
                }
                

            }

        }

        cout << complete_course ;

        return complete_course ==numCourses ;

    }
};