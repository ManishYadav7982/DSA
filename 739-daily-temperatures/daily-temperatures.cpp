class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size() ;
        vector<int >ans(n,0);

        stack<pair<int,int>> st ;
        int i = n-1 ;
        while(i>=0){

            while(!st.empty() &&  temperatures[i] >= st.top().first ){
                st.pop() ;
            }

           ans[i] = !st.empty() ? st.top().second - i  : 0;
            st.push({temperatures[i] , i  }) ;
            i-- ;
        }

        return ans;
    }
};