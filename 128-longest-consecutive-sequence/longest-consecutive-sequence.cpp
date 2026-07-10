class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int > st;
        for(int i : nums){
            st.insert(i);
        }
        int maxlen = 0 ;

        for(int i : st){

            if(st.find(i-1 ) == st.end()){
                int curr = i ;
                int len = 1 ;
                while(st.find(curr +1 ) != st.end()){
                    curr++ ;
                    len++ ;
                }
                maxlen = max(maxlen , len );

                
            }
        }
        return maxlen ;


        
    }
};