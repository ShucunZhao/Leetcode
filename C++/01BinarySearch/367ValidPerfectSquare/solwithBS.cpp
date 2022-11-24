class Solution {
public:
    bool isPerfectSquare(int num) {
        long l=0,r=num;
        long m;
        while(l<=r){
            m = l+(r-l)/2;
            if(m*m<num){
                l = m+1;
            }
            else if(m*m>num){
                r = m-1;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};