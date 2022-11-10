class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 0;//10
        for(int i=2;i<=n;i++){
            dp[i] = min((dp[i-1]+cost[i-1]), (dp[i-2]+cost[i-2]));//KeyPoint: Infer the inference formula.
            // cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
        }
        return dp[n];
    }
};