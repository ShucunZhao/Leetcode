class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*
            dp[i][0]: unhold stock in day i
            dp[i][1]: hold stock in day i

            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-fee+prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i])

            dp[0][0] = 0
            dp[0][1] = -fee-prices[0] 
        */
        vector<vector<int> > dp(prices.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];//KeyPoint: Accoording to question, buy in is not cost fee, only sale out should pay fee.
        for(int i=1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-fee+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
    }
};