class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int min_ele_ind = 0, max_ele_ind = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[min_ele_ind]) {
                min_ele_ind = i;
            }
            if (nums[i] > nums[max_ele_ind])
                max_ele_ind = i;
        }
       
       int a = min(min_ele_ind, max_ele_ind);
        int b = max(min_ele_ind, max_ele_ind);

        int front = b + 1;
        int back = n - a;
        int bothsides = (a + 1) + (n - b);

        return min({front, back, bothsides});


    }
};