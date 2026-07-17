class Solution {
public:
    int maxDepth(string s) {
        int d = 0 ;
        int maxd = 0 ;
        for(auto i :s){
            if(i == '(') d++ ;
             if(i == ')') d-- ;
            //  cout << d << "  " ; 
            maxd = max(d , maxd ) ;
        }

        return maxd;
        
    }
};