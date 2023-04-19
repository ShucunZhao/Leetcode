class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0){
            return 1;
        }
        else if(exponent>0){
            return base*Power(base, exponent-1);
        }
        return 1/(base*Power(base, abs(exponent)-1));
    }
};