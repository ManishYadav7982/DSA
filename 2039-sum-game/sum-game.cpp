class Solution {
public:
    bool sumGame(string nums) {

        int n = nums.size() ;

        int leftKnowSum = 0 ;
        int rightknowSum = 0 ;

        int leftQnMark = 0 ;
        int rightQnMark = 0 ;


        for(int i=0;i<n;i++){
            if (nums[i] == '?' ){
                if(i < n /2){
                    leftQnMark++ ;
                }
                else rightQnMark++ ;

            }
            else{
                if(i < n/2){
                    leftKnowSum += nums[i] - '0';
                }
                else {
                    rightknowSum+= nums[i] - '0';
                }
            }
        }


        if((leftQnMark + rightQnMark) % 2 == 1){
            return true ;
        }

        int l = 2*leftKnowSum + 9*leftQnMark ;
        int r = 2*rightknowSum + 9*rightQnMark ;
        if(l==r){
            return false ;
        }

        return true ;
        
    }
};