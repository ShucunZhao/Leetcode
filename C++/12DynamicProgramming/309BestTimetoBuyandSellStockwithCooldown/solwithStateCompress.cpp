class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2) return 0;
        vector<vector<int> > dp(prices.size(), vector<int>(3, 0));
        /* Compress into only three states:
            dp[x][0]: hold
            dp[x][1]: unhold
            dp[x][2]: cold
        */
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        for(int i=1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][2]-prices[i], dp[i-1][0]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);
            dp[i][2] = dp[i-1][1];
        }  
        return dp[prices.size()-1][1];
    }
};