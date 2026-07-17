class Solution {
public:
    int beautySum(string s) {
    int n = s.size() ;
    int ans = 0 ;
    for(int i = 0 ;i<n;i++){
        cout <<"\n" ;
        unordered_map<char , int>mp;
        for(int j=i;j<n;j++){
            mp[s[j]]++ ;
            int max= INT_MIN ;
        int min = INT_MAX ;
        for(auto it : mp){
            if(it.second > max ) max = it.second ;
            if(it.second < min ) min =it.second ;
        }
        // cout << "MX" <<max << "   " << "MN" << min <<endl ;
        ans+= max-min ;
        }
        // for(auto  ele: mp){
        //     cout <<ele.first << "  " << ele.second  << "\n" ;
        // }
    
    }


    return ans ;
    }
};