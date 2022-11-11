// dp[i]: i represents the current number "n" while dp[i] represents the maximum product after breaking.
/* Inference formula:
   dp[5] = dp[1]*dp[4], dp[2]*dp[3]
   dp[8] = dp[1]*dp[7], dp[2]*dp[6], dp[3]*dp[5], dp[4]*dp[4]
   ---------------------------------------
   for i form 4 to n, j from 1 to i/2:
   dp[i] = max(dp[i], dp[j]*dp[n-j])
*/
// Initialization: dp[1] = 1; dp[2] = 2; dp[3] = 3;(When 1~3 as the being break combinations they cannot be break further because it will make them smaller.)
// Interate order: From front to back.

class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i/2;j++){
                dp[i] = max(dp[i], dp[j]*dp[i-j]);//1*3,2*2;
                // cout<<"i:"<<i<<"j:"<<j<<"dp[i]:"<<dp[i]<<endl;
            }
        }
        return dp[n];
    }
};