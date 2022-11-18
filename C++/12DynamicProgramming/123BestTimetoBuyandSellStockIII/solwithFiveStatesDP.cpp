/* The most different with 121 and 122 is there are five states here.
 * dp array: The size of dp is prices.nums x 5 
             dp[i][0]: do nothing at No.i day.
             dp[i][1]: first time hold the stock at No.i day.
             dp[i][2]: first time abandon current holding stock at No.i day.
             dp[i][3]: second time hold the stock at No.i day.
             dp[i][4]: second time abandon the stock at No.i day.
 * Inference formula: dp[i][0] = dp[i-1][0]
                      dp[i][1] has two cases: I.has first time brought in before i day: dp[i][1] = dp[i-1][1]
                                              II.first buy in at No.i day: dp[i][1] = dp[i-1][0] - prices[i]
                then  dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
                      dp[i][2] has two cases: I.has first time abandon the stock befor i day: dp[i][2] = d[i-1][2]
                                              II.first time sale out at No.i day: dp[i][2] = dp[i-1][1] + prices[i]
                then  dp[i][2] = max(d[i-1][2], dp[i-1][1] + prices[i])
                      dp[i][3] has two cases: I.has second time brought in before i day: dp[i][3] = dp[i-1][3]
                                              II.second buy in at No.i day: dp[i][3] = dp[i-1][2] - prices[i]
                then  dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i])
                      dp[i][4] has two cases: I.second time abandon the stock before i day: dp[i][4] = dp[i-1][4]
                                              II.second time sale out at No.i day: dp[i][4] = dp[i-1][3] + prices[i]
                then  dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i])
 * Initialization:  from infer formula we know the dp[0][0~4] should be initialized:
                    dp[0][0] = 0; dp[0][1] = -prices[0]; dp[0][2] = 0; dp[0][3] = -prices[0]; dp[0][4] = 0.
 * print dp array for debug.
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(5, 0));
        // dp[0][0] = 0;
        dp[0][1] = -prices[0];
        // dp[0][2] = 0;
        dp[0][3] = -prices[0];
        // dp[0][4] = 0;
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