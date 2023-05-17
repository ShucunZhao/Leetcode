
class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        /*
            dp[i][0]: the max can get if in i days unhold the stock
            dp[i][1]: the max can get if in i days hold the stock 
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);//Difference here: if you only allow to buy 
                                                             //and sale once, each time you hold is only
                                                            //detract the prices directly rather than the 
                                                            //previous unhold days.
            so the dp[i][1] should be max(-prices[i], dp[i-1][1]);
        */
        vector<vector<int> > dp(prices.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(-prices[i], dp[i-1][1]);
        }
        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};