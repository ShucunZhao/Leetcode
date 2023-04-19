class Solution {
public:
    double Power(double base, int exponent) {
        /*
            Sol with quick power:
            X^n if X=5, n=13
                                                8  4  2 1 
            we convert n into binary form: 13 = 8 + 4 + 0 + 1
                                                2^3 2^2 2^1 2^0
            X^n=(5)^13 = (5^8)*(5^4)*(5^0)*(5^1)
                    ans = 1;
                    Q = X;
                    while(n){
                        if(n&1) ans*=Q;
                        Q = Q*Q;
                        n>>1;
                    }
        */
        if(exponent<0){
            exponent = -exponent;
            base = 1/base;
        }
        double ans = 1;
        double Q = base;
        while(exponent){
            if(exponent&1) ans*=Q;
            cout<<ans<<endl;
            Q*=Q;
            exponent>>=1;
        }
        return ans;
    }
};