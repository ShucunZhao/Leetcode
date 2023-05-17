class Solution {
public:
    int Sum_Solution(int n) {
        /*
            Sol with the formula of the sum of Arithmetic Progression first n items:
            Sn = ((a1+an)*n)/2
            and an = a1 + (n-1)*d where d is 1 so that an = a1 + (n-1)
            so:
                Sn = ((a1+a1+(n-1))*n)/2
                   = ((2a1+n-1))*n/2
                   where a1 = 1
                   so:
                    Sn = ((2+n-1)*n)/2
                       = ((n+1)*n)/2
                       = (n^2+n)/2
                       = (n^2+n)>>1
        */   
        return (int)(pow(n,2.0)+n)>>1;
    }
};