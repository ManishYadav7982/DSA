class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        
        int n = lights.size() ; // size of light 
        int m = arrivalTime.size() ; // size of arrivalTime

        int mx_light = INT_MIN ; 
        for(int i : lights ){
            mx_light = max(mx_light , i ) ;

        }
        int ans =0;
        for(int i =0;i<m;i++){
            int r = arrivalTime[i] % period ; 
            if(r >= mx_light){
                ans = max(ans , period - r) ;
            }
        }

        return ans ;

    }
};