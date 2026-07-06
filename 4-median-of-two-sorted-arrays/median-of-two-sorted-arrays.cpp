class Solution {
    private :

    void print(vector<int > &v ){
        for(int i : v){
            cout << i << " ";
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int > temp ;
        int i = 0 ;
        int j = 0 ;

        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++ ;
            }
            else {
                temp.push_back(nums2[j]);
                j++ ;
            }
        }

        while(i < nums1.size()){
            temp.push_back(nums1[i]);
            i++ ;
        }
        while(j < nums2.size() ){
            temp.push_back(nums2[j]);
            j++ ; 
        }

        print(temp );

        int n = temp.size();
        // cout << " n " << n ; 

        double  val  ;
        int ind = n/2 ;
        if(n %2 == 0 ){
            val = temp[ind] + temp[ind -1 ];
             return val/2.00000 ;
        }
        else{
          val = temp[ind];
          return val ;

        }

    }
};