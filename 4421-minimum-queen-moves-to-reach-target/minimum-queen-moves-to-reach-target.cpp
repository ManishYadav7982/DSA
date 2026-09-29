class Solution {
public:
    int minQueenMoves(vector<int>& source, vector<int>& target) {
       int s_row = source[0] ;
       int s_cl = source[1] ;
       int t_row = target[0] ;
       int t_cl = target[1] ;

       if(s_row == t_row && s_cl == t_cl) return 0 ;
       else if(abs(s_row - t_row) == abs(s_cl - t_cl)) return 1 ;
       else if (( s_row == t_row) || (s_cl == t_cl))return 1 ;
       else return 2 ;

    }
};