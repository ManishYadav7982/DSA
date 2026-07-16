class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        string  s = num ;
        for(int i = n-1 ; i >= 0 ;i--){
            string temp2 = "" ;
            temp2 += s[i] ;
             int temp = stoi(temp2);
             if(temp % 2 != 0 ) return s ;
            s.pop_back() ;
        }


        return "";

        
    }
};