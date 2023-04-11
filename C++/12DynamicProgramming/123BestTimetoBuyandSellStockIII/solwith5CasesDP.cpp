class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            Five situations:
            dp[i][0]: the max profit we can get if do nothing in day i
            dp[i][1]: the max profit we can get if the first time to hold stock in day i.
            dp[i][2]: the max profit we can get if the first time to abandon stock in day i.
            dp[i][3]: the max profit we can get if the second time to hold stock in day i.
            dp[i][4]: the max profit we can get if the second time to abandon stock in day i.

            dp[i][0] = dp[i-1][0]
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1])
            dp[i][2] = max(dp[i-1][1]+prices[i], dp[i-1][2])
            dp[i][3] = max(dp[i-1][2]-prices[i], dp[i-1][3])
            dp[i][4] = max(dp[i-1][3]+prices[i], dp[i-1][4])

            dp[0][0] = 0;
            dp[0][1] = -prices[0];
            dp[0][2] = 0;
            dp[0][3] = -prcies[0];
            dp[0][4] = 0
        */
        vector<vector<int> > dp(prices.size(), vector<int>(5));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;
        for(int i=1;i<prices.size();i++){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
            dp[i][2] = max(dp[i-1][1]+prices[i], dp[i-1][2]);
            dp[i][3] = max(dp[i-1][2]-prices[i], dp[i-1][3]);
            dp[i][4] = max(dp[i-1][3]+prices[i], dp[i-1][4]);
        }
        return dp[prices.size()-1][4];
    }
};