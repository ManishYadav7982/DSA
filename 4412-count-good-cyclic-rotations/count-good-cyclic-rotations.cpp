class Solution {
public:
    int countGoodRotations(vector<int>& nums) {

        int n = nums.size() ;

        int ind = 0 ;

        vector<long long  > prefix(n , 0 ) ;
        int sum = 0 ; 

        prefix[0] = nums[0] ;

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i] ;
        }

        for(int i : prefix){
            cout<< i << ' ' ; 
        }


        int i = n/2  ;

        int j = n-1 ;
        int cnt = 0 ;
        while ( i <=j ){
            if (prefix[i] - prefix[ind] !=  prefix[j] - prefix[i] + prefix[ind]) cnt++  ;
            i++ ;
            ind++ ;
        }
        // if(i == j ){
        //     if(prefix[j] - prefix[i] + prefix[ind] > prefix[i] - prefix[ind] ) cnt++ ;
        // }





        return cnt  ;
        
    }
};