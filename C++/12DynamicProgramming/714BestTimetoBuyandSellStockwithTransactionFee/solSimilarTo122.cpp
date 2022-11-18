class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int> > dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;//You need to initial dp[0][1] with 0 rather than -fee here is because 
                    //if you want profit is max you need to buy nothing instead of buy it and sale it at the same day.
        for(int i=1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]-fee);//First different: need to minus fee when saling out.
        }
        return max(dp[prices.size()-1][1], dp[prices.size()-1][0]);//Second different: need to compare if sale the stock is max or just keep it.
    }
};