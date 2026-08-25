class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<int> temp(102 , 0) ;

        for(int i : nums){
            if( i % k == 0 ){
                int store = i / k ;
                temp[store] = 1 ;
            }
        }

        for(int i =1 ;i< temp.size() ; i++){
            if(temp[i] == 0 ) return (k*i) ; 
        }


    return -1  ;
        
    }
};