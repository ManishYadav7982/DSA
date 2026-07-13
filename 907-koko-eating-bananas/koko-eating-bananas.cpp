class Solution {
    private:
    bool check(vector<int> nums , int mid , int h ){
        long long  time = 0 ;
         int temp = mid ;
        for(int i : nums){
            if(i % temp != 0 ){
                time++ ;
            }
            time += i / temp;

        }
        return h >= time ;
        
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi  = *max_element(piles.begin() , piles.end());
        int l = 1 ;
        int hi = maxi ;
        int ans = maxi ;

        while(l <= hi ){
            int mid = l + ( hi - l)/2;
            if(check(piles , mid , h  )){
                ans =mid;
                hi=mid-1;
            }
            else{
                l =mid+1;
            }
        }

        return ans ;

        
    }
};