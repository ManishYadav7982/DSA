class Solution {
    private:

    bool isValid(string &curr){
        int cnt = 0;
        for(auto i : curr){
            if(i=='(') cnt++ ;
            else cnt-- ;

            if(cnt < 0 ) return false ;
        }

        return cnt ==  0 ;
    }
    
    void made( vector<string>&ans , string &curr , int n ){
        if((int)curr.size() == 2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }

            return ;
        }

            // backtracking 

            curr.push_back(')');
            made(ans , curr ,n );
            curr.pop_back();

            curr.push_back('(');
            made(ans , curr , n );
            curr.pop_back();
        
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr = "" ;
        vector<string>ans ;
        made(ans , curr , n );
        return ans ; 
    }
};