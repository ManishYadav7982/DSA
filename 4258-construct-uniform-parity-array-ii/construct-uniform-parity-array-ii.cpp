class Solution {

    private :

    bool checkEven(vector<int>& nums1 , int MinOdd , int n ){
        for(int i = 0 ; i < n ;i++){
            if(nums1[i] % 2 != 0 ){
                if(  nums1[i] - MinOdd <= 0  ){
                    return false ;
                }
            }
        }
        return true ;
    }

    bool checkOdd(vector<int>& nums1 , int MinOdd , int n ){

        for(int i = 0;i<n;i++){
            if(nums1[i] % 2== 0 ){
                if( nums1[i] - MinOdd <= 0  ){
                    return false ;
                }
            }
        }

        return true ;




    }
public:
    bool uniformArray(vector<int>& nums1) {
        
        int n =  nums1.size() ;
        // sort(nums1.begin() , nums1.end()) ;

        // if(nums[0] % 2 == 0 ){
        //     firstEvenInd = 0  ;
        //     for(int i = 0; i < n  ;i++){
        //         if(nums1[i] % 2 != 0 ){
        //             firstoddInd = i ; 
        //             break ; 
        //         }
        //     }
        // }
        // else {
        //     lastoddInd = 0   ;
        //       for(int i = 0 ; i < n ;i++){
        //         if(nums1[i] % 2 == 0 ){
        //             firstEvenInd = i ; 
        //             break ; 
        //         }
        //     }
        // }


        int MinEven = 1e9;
        int MinOdd = 1e9 -1 ;

        for(int i : nums1){
            if(i  % 2 == 0  ){
               MinEven = min(MinEven , i ) ; 
            }
            else {
                MinOdd = min(MinOdd , i ) ; 
            }
        }

        cout << MinEven << ' ' << MinOdd ; 

        if(checkEven(nums1 , MinOdd , n  )) return true ;
        
        if(checkOdd(nums1 , MinOdd , n ) ) return true ;
        

        else return false ;
    }
};