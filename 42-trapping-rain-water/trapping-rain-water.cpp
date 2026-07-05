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
private:
    void print(vector<int> v) {
        for (int ele : v) {
            cout << ele << ' ';
        }
    }

public:
    int trap(vector<int>& height){
        int n = height.size();
        vector<int > left_max(n , 0);
        vector<int > right_max(n , 0 );

        left_max[0] = height[0];
        right_max[n-1] = height[n-1];


        for(int i = 1 ; i< n ;i++){
            left_max[i] = max(left_max[i-1] , height[i]) ;
        }
        for(int i = n-2 ; i >= 0  ;i--){
            right_max[i] = max(right_max[i+1] , height[i]) ;
        }

        // print(left_max);
        // cout << endl ;
        // print(right_max) ;
        int max_water = 0 ; 
        for(int i = 0 ; i< n ;i++){
            int water = min(left_max[i] , right_max[i]);
            max_water += water - height[i];

        }
        return max_water  ; 



    }
};