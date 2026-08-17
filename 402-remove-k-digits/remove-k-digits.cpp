class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n = nums.size() ;
        stack<int> st ;
        int i=1;
        st.push(nums[0] -'0') ;
        while(i <n){
            while(st.size() > 0 && nums[i] - '0' < st.top() && k){
                st.pop() ;
                k-- ;
            }
            st.push(nums[i] -'0') ;
            i++ ;
        }

        while( k && st.size() >0){
            st.pop() ;
            k-- ;
        }
        string ans = "" ;
        while(!st.empty()){
            ans+= st.top() + '0';
            st.pop() ;
        }
        // cout << ans; 

        // cout << endl ;
        int j = ans.size() -1 ;
        while(j >0 && ans[j] == '0'){
            ans.pop_back() ;
            j-- ;
        }

        // cout << ans; 
        reverse(ans.begin() , ans.end()) ;
        if(ans == ""){
            return "0" ;
        }
        else return ans ;
    }
};