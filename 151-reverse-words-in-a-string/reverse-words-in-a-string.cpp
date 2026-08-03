class Solution {

    private :
    void made(string &ans , string &s , int left , int right ){
        // cout << left << "  " <<  right << ' ' ; 
        left++ ; // so that main left not changes ;
        while(left <= right ){
            ans+= s[left] ;
            left++ ; 
            // cout << s[leftt] << ' ' ; 
        }
        
        
    }
public:
    string reverseWords(string s) {
        // string temp ="" ;
        int n = s.size() ;
        int i = n-1;
        int j = 0 ;
        string ans = "" ;
        while(s[i] == ' '){
            i-- ;
        }
        while(s[j] == ' '){
            j++ ;
        }

        int second_ind_i = i ;
        // cout << second_ind_i << "  " << i ;

        while(j <= second_ind_i ){
            if(s[second_ind_i] == ' '){
                // cout << second_ind_i << "  " << i ;
                made(ans , s ,second_ind_i , i  ) ;
                ans+=' ' ;
                while(s[second_ind_i] == ' '){
                   second_ind_i-- ;
                }
                i = second_ind_i ; 
            }
            else{
               second_ind_i-- ;
            }
        }
        made(ans , s ,second_ind_i , i  ) ;
        return ans ;
    }
};