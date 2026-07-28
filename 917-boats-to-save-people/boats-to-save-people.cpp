class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin() , people.end());

        int l=0 ;
        int h = n-1 ; // 
        int cnt =0 ;
        while(l <=h){
            if(people[l] + people[h] <= limit  ){
                cnt++ ;
                l++ ;
                h--;
            }
           else cnt++ , h-- ;
        //    cout << cnt << "H : " << h << "L : " << l << ' ' ;
        }
        // if(l==h){
        //     cnt++ ;
        // }
        return cnt ;



    }
};