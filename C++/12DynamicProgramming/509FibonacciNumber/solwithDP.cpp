class Solution {
public:
    int fib(int n) {
        if(n<1) return n;//Edge situation.
        vector<int> dp(n+1);//Step 1: Determine dp array and it's meaning.
        dp[0] = 0;//Step 3: Initialize dp array.
        dp[1] = 1;
        for(int i=2;i<=n;i++){//Step4: Determine iterative order.
            dp[i] = dp[i-1] + dp[i-2];//Step 2: Determine state formula. 
            // cout<<dp[i]<<endl;//Step5: Print the dp array to debug.
        }
        return dp[n];
    }
};