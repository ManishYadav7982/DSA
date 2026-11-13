class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
       long long individual= ( 1LL * need1 * cost1 ) +( 1LL  * need2 * cost2) ;

        long long both  =1LL *  min( need1 , need2 ) * costBoth; 

        if(need1 > need2){
            long long  diff = need1 - need2 ;
            long long _both = diff * costBoth ;
            long long _ind = diff * cost1 ;

            both += min(_both , _ind) ;

        }else{
            long long  diff = need2 - need1 ;
            long long _both = diff * costBoth ;
            long long _ind = diff * cost2 ;

            both += min(_both , _ind) ;
        }

        return min(individual, both ) ; 
    }
};