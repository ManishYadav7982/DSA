class Solution {
    private :

    int f(int &num){
        int cnt =0 ;
        while(num >0){
            cnt++ ;
            num = num/10 ;
        }
        return cnt ; 
    }
public:
    int compress(vector<char>& chars) {

        int l =0 , r = 0 ;

        while( r < chars.size() ){
            int cnt =0 ;
            while( r < chars.size() &&  chars[l] == chars[r]  ){
                cnt++ ;
                r++ ;
            }
            
            if(cnt !=1 ){
                string temp = to_string(cnt) ;
                for(int i=0;i<temp.size() ;i++){
                    chars[l+1] = temp[i] ;
                    l++ ;
                }
                 int extra = r - l - 1;
                chars.erase(chars.begin() + l + 1,
                            chars.begin() + l + 1 + extra);

                r = l + 1;
                
            }
            
            l=r;
           
        }

        return chars.size() ;
        
    }
};