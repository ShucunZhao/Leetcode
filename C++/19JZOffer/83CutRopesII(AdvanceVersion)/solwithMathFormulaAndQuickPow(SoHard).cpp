class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number long长整型 
     * @return long长整型
     */
    long long cutRope(long long number) {
        // write code here
        /*
            mod operation formula:
                (X1 + X2)%p = (X1%p + X2%p)%p
                (X1 * X2)%p = (X1%p*X2*p)%p (when X1*X2 < p)

            So we need to calculate the (a^n)%p
            then:
                res(n) = a^n%p = (a^(n-1)%p * a%p) %p
                             = (a^(n-1)%p * a) %p [Because a is smaller than p, so a%p is equal to a]
                             = (res(n-1)*a)%p

        And:   res(n-1) = a^(n-1)%p = (res(n-2)*a)%p
                ......
               res(1) = (1*a)%p.
        */
        if(number==2) return 1;
        if(number==3) return 2;
        long long res = number/3;
        long long mod = number%3;
        long long makeUp = 1;
        long long p = 998244353;
        if(mod==0){
            return myPow(3, res)*makeUp%p;
        }
        else if(mod==1){
            res--;
            makeUp=4;
            return myPow(3,res)*makeUp%p;
        }
        makeUp=2;
        return myPow(3,res)*makeUp%p;
    }
    //Calculate the a^n % p
    long long myPow(long long a, long long n){
        long long res = 1;
        long long p = 998244353;
        while(n){
            if(n&1){
                res = (res*a)%p;
            }
            a = a*a%p;
            n>>=1;
        }
        // for(int i=0;i<n;i++){
        //     res = (res*a)%p;
        // }
        return res;
    }
};