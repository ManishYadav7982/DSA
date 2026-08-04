class Solution {
    private:
    double findpow(double x , long long n ){
        if(n == 0 ) return 1;

        double half =findpow(x,n/2) ;
        double res = half*half ;

        if(n%2 == 1){
            res = x*res ;
        }

        return res ; 
    }

public:
    double myPow(double x, int n) {
        long long N= n ; 
       if(n < 0 ) x = 1/x , N = -N; 
       return findpow(x , N ) ; 

    }
};