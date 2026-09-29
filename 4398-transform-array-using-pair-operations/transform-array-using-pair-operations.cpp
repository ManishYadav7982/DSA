class Solution {
    using ll = long long  ;

public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        int n = source.size()  ;
        ll sum_s = 0 ;
        ll sum_t = 0 ;
        for(int i = 0 ;i<n;i++){
            sum_s += source[i];
            sum_t += target[i];
        }

        return sum_s == sum_t ;
    }
};