class Solution {
public:
    int integerBreak(int n) {
        /*
            initial case:
            n==2  return 1;
            n==3  return 2; 
            dp[i] is the max break product of number i.
            dp[1] = 1
            dp[2] = 2;
            dp[3] = 3;
            dp[i] = max(dp[i], dp[i]*dp[n-i]); i from 1 to n/2.
            dp[4] = dp[1]*dp[3] : 3   (i from 1 to 2)
                    dp[2]*dp[2] : 4
                    4
            dp[5] = dp[1]*dp[4] : 4   (i from 1 to 2)
                    dp[2]*dp[3] : 6
                    6
            dp[6] = dp[1]*dp[5] : 6   (i from 1 to 2)
                    dp[2]*dp[4] : 8
                    dp[3]*dp[3] : 9 
                    9
            dp[7] = dp[1]*dp[6] : 9  (i from 1 to 3)
                    dp[2]*dp[5] : 12
                    dp[3]*dp[4] : 12
                    12
            dp[8] = dp[1]*dp[7] : 12 (i from 1 to 4)
                    dp[2]*dp[6] : 18
                    dp[3]*dp[5] : 18
                    dp[4]*dp[4] : 16
                    18 
            dp[9] = dp[1]*dp[8] : 18 (i from 1 to 4)
                    dp[2]*dp[7] : 24
                    dp[3]*dp[6] : 27
                    dp[4]*dp[5] : 24
                    24
            dp[10] = dp[1]*dp[9] : 24 (i from 1 to 5)
                     dp[2]*dp[8] : 36
                     dp[3]*dp[7] : 36
                     dp[4]*dp[6] : 36
                     dp[5]*dp[5] : 36
                     36
        */
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
            }
        }
        return dp[n];
    }
};