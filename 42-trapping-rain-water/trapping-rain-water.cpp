// //cp

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int left = 0;
//         int right = n - 1;
//         int leftMax = 0;
//         int rightMax = 0;
//         int water = 0;

//         while (left < right) {
//             if (height[left] < height[right]) {
//                 if (height[left] >= leftMax) {
//                     leftMax = height[left];
//                 } else {
//                     water += leftMax - height[left];
//                 }
//                 left++;
//             } else {
//                 if (height[right] >= rightMax) {
//                     rightMax = height[right];
//                 } else {
//                     water += rightMax - height[right];
//                 }
//                 right--;
//             }
//         }

//         return water;
//     }
// };




class Solution {
    private :
    void print(vector<int > v ){
        for(int ele : v){
            cout << ele << ' ';
        }
    }
public:
    int trap(std::vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        // Arrays to store the maximum heights to the left and right of each index
        std::vector<int> left_max(n);
        std::vector<int> right_max(n);
        int water_trapped = 0;

        // 1. Fill left_max array using a forward for loop
        left_max[0] = height[0];
        for (int i = 1; i < n; i++) {
            left_max[i] = std::max(left_max[i - 1], height[i]);
        }

        // 2. Fill right_max array using a backward for loop
        right_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right_max[i] = std::max(right_max[i + 1], height[i]);
        }

        print(left_max) ; 
        cout << endl ;
        print(right_max);

        // 3. Calculate the trapped water using a standard for loop from 0 to n
        for (int i = 0; i < n; i++) {
            // The water level is bounded by the smaller of the two maximums
            int water_level = std::min(left_max[i], right_max[i]);
            
            // Trapped water at index i is water level minus the bar's own height
            water_trapped += water_level - height[i];
        }

        return water_trapped;
    }
};