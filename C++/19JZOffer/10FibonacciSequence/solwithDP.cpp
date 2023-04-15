class Solution {
public:
    int Fibonacci(int n) {
        /*
            dp[i] = dp[i-1] + dp[i-2]
            dp[1] = 1, dp[2] = 1; 
        */
        if(n<3) return 1;
        vector<int> dp(n+1, 1);
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};