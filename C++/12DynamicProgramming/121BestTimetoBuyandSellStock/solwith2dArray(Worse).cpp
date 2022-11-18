/* 
 * dp array: use 0/1 to represent if hold the stock:
             dp[i][0]: The current money you have when you hold the stock in the number i day.
             dp[i][1]: The current money you have when you didn't hold the stock in the number i day.
 * Infer formula: I.for dp[i][0]: if you have hold the stock for previous days, dp[i][0] is same as dp[i-1][0],
                                  else if you buy the stock in the number i day, dp[i][0] should be -prices[i].
                  therefore: dp[i][0] = max(dp[i-1][0], -prices[i])
                  II. for dp[i][1]: if you have sold the stock previous days ago, dp[i][1] is same as dp[i-1][1],
                                    else if you sold the stock in the number i day, dp[i][1] should be prices[i]+dp[i-1][0];
                III. The final ans should be dp[i][1] because whaterver the sold money will always larger than holding stock money.
 * Initialization: from infer formula we can see the dp[0][0] and dp[0][1] should be initialized.
                   dp[0][0] = -prices[0]: if hold the stock in first day the money should be negative prices[0].
                   dp[0][1] = 0: means you don't hold the stock at first day so the money you get is 0.
                   
 * Iterate order: from front to back.
 * Print the dp array to debug.
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(2,0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i=1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][0], -prices[i]);
            dp[i][1] = max(dp[i-1][1], prices[i]+dp[i-1][0]);
        }
        return dp[prices.size()-1][1];
    }
};