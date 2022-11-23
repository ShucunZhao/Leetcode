class Solution {
public:
    int mySqrt(int x) {
        long long l =0, r=x;
        long long m;
        while(l<=r){
            m = l+(r-l)/2;
            if(m*m>x){
                r = m-1;
            }
            else if(m*m<x){
                l = m+1;
            }
            else{
                return m;
            }
        }
        return r;
    }
};