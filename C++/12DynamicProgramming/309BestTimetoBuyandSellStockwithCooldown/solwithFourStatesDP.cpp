/*
 * dp array: Four different states dp[0][0~3]
             dp[i][0]: keep the buy in state, buy at previous day or No.i day.
             dp[i][1]: sale out stock two days ago(which means pass the colddown day) and keep state for now.
             dp[i][2]: sale out stock in No.i day.
             dp[i][3]: today is freeze day.
 * Infer formula:
             I.for dp[i][0]: if buy previous day: dp[i][0] = dp[i-1][0]
             else if buy tody: I.previous day is freeze: dp[i][0] = dp[i-1][3]-prices[i]
                               II.previous day is keep saling out state: dp[i][0] = dp[i-1][1]-prices[i]
                then dp[i][0] = max(dp[i-1][0], max(dp[i-1][3],dp[i-1][1])-prices[i])
             II.for dp[i][1] : if previous day is also keep saling and not freeze state: dp[i][1] = dp[i-1][1]
                               else if previous day is freeze day: dp[i][1] = dp[i-1][3]
                then dp[i][1] = max(dp[i-1][1],dp[i-1][3])
             III.for dp[i][2]: only one case, brought yesterday and sale tody: dp[i][2] = dp[i-1][0] + prices[i]
             IV. for dp[i][3]: only one case, sold out stock yesterday: dp[i][3] = dp[i-1][2] 
  * Initialization: dp[0][0] = -prices[0]; dp[0][1] = 0; dp[0][2] = 0; dp[0][3] = 0;
  * Iterate order: from front to back.
  * Print dp to debug.
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int> > dp(prices.size(), vector<int>(4, 0));
        int m = prices.size();
        dp[0][0] = -prices[0];
        // dp[0][1] = 0;
        // dp[0][2] = 0;
        // dp[0][3] = 0;
        for(int i=1;i<m;i++){
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][3],dp[i-1][1])-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0]+prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return max(dp[m-1][1], max(dp[m-1][2], dp[m-1][3]));
    }
};