class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            dp[i][0] the max profit can get in day i if unhold stock.
            dp[i][1] the max profit can get in day i if hold stock.

            dp[i][0] = max(dp[i-1][1] + prices[i], dp[i-1][0])//TWo cases: sold today, sold in previous days. 
            dp[i][1] = max(-prices[i], dp[i-1][1])//Two cases: buy today(KeyPoint: if buy there is neccessary from precious day unhold to buy, 
                        if hold in previous day we also can buy tody, so it's just -prices[i] here.), bought in precious days and keep to today.
            Initialization: 
            dp[0][0] =  0;
            dp[0][1] = -prices[0];
        */
        vector<vector<int> > dp(prices.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][1]+prices[i], dp[i-1][0]);
            dp[i][1] = max(-prices[i], dp[i-1][1]);
        }
        /*
        for(int i=0;i<prices.size();i++){
            cout<<"dp["<<i<<"]"<<"[0]:"<<dp[i][0]<<","<<"dp["<<i<<"]"<<"[1]:"<<dp[i][1]<<endl;
        }
        */
        //return max(dp[prices.size()-1][0], dp[prices.size()-1][1]);
        return dp[prices.size()-1][0];//Because unhold in the last day will always get more money.
    }
};