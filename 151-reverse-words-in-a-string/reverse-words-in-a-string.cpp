class Solution {

    private :
    void made(string &ans , string &temp){
        int n = temp.size() ;
        int j = n-1 ;
        while(j >= 0){
            ans+=temp[j] ;
            j-- ; 
        }
        temp.erase() ;
        
    }
public:
    string reverseWords(string s) {
        string temp ="" ;
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

        while(j <= i ){
            if(s[i] == ' '){
                made(ans , temp) ;
                ans+=' ' ;
                while(s[i] == ' '){
                    i-- ;
                }
            }
            else{
                temp+=s[i] ;
                i-- ;
            }
        }
        made(ans , temp) ; 
        return ans ;
    }
};