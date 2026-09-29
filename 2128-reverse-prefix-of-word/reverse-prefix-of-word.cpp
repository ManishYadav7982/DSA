class Solution {
    private :
    void reverse(int start , int end , string &word){
        while(start<=end){
            swap(word[start] , word[end]);
            end-- ;
            start++ ;
        }
    }
public:
    string reversePrefix(string word, char ch) {
        int n = word.size() ;
        
        for(int i = 0 ;i<n;i++){
            if(word[i] == ch ){
                reverse(0, i , word);
                return word ;
            }
        }
        return word ;
        
    }
};