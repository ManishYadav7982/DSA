// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<string> temp  = strs;
//        for(int i = 0 ; i< temp.size() ;i++){
//         sort(temp[i].begin() , temp[i].end());
//        }

//     //    unordered_map <string , vector > mp ;

//     //    for(auto ele : temp ){
//     //     if(mp.find(ele) != end()){
//     //         mp[ele] =

//     //     }

//     //    }

//      vector<vector<string>> ans ;
//      unordered_set<string> mp ;
//     for(int i = 0 ;i < temp.size() ;i++){
//         if(mp.find(temp[i])  != mp.end()) continue ;
//         mp.insert(temp[i]) ;
//         vector<string> store ;
//         string ele = temp[i];
//         store.push_back(strs[i]);
//         for(int j = i+1 ; j < temp.size() ;j++){
//             if(temp[j] == ele ){
//                 store.push_back(strs[j]) ;
//             }

//         }
//         ans.push_back(store);
//     }

//         return ans ;

//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Maps the sorted version of a string to all its original anagrams
        unordered_map<string, vector<string>> mp;

        for (const string& s : strs) {
            string sorted_s = s;
            sort(sorted_s.begin(), sorted_s.end()); // O(K log K)
            mp[sorted_s].push_back(s);              // O(K) hash map insertion
        }
 
        // Collect results from the

        // for (const auto& [key, anagrams] : mp) {
        //     cout << "Key (Sorted): " << key << " -> Anagrams: ";
        //     for (const string& str : anagrams) {
        //         cout << str << " ";
        //     }
        //     cout << endl;
        // }

        vector<vector<string>> ans;
        for (auto& pair : mp) {
            ans.push_back(pair.second);
        }

        return ans;
    }
};