class Solution {
public:
    int minChanges(string s) {
        int n = s.size() ; 
        int count = 0;

        for(int i = 0; i <n; ) {
            if(s[i] != s[i + 1]) {
                count++;
            }
            i+= 2 ;
        }

        return count;
    }
};