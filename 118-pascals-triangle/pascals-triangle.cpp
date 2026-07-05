class Solution {
    private :
    void print(vector<int> v){
        for(int i : v){
            cout << i << ' ';
        }
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans ; 
        int n = numRows ;
        for(int i = 0 ; i < n;i++){
            vector<int > temp ;
            for(int j = 0 ; j <= i;j++){
                if(j == i || j == 0 ){
                    temp.push_back(1);
                }
                else{
                    int pushh = ans[i-1][j-1] + ans[i-1][j];
                    temp.push_back(pushh);
                }
            }
            // print(temp) ; 
            // cout << endl ;
            ans.push_back(temp );
        }

        return ans ; 
    }
};