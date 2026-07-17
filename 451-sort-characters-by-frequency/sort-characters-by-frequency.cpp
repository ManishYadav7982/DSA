class Solution {
public:
    string frequencySort(string s) {
        int n= s.size() ;

       unordered_map<char , int  > mp ;
       for(auto i: s){
        mp[i]++ ;
       }

    //    for(auto  i : mp ){
    //     cout << i.first << " " <<i.second << endl ;
    //    }

       priority_queue<pair<int , char >> pq ;

       for(auto  it : mp){
        pq.push({it.second , it.first}) ;
       }

       string ans = "";

       while(pq.size() > 0 ){
        int temp = pq.top().first;
        char ch = pq.top().second ; 
        pq.pop() ;
        while(temp){
            ans+= ch ;
            temp-- ;
        }
       }


    return ans ;

        
    }
};