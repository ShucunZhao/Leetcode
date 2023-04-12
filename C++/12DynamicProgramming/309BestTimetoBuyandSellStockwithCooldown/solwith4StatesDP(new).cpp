class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            dp[i][0]: hold in day i
            KeyPoint: Pay attention the two unhold situations:
                dp[i][1]: uhold in previous two days ago from day i
                dp[i][2]: unhold in today day i
            dp[i][3]: cooldown today in day i

            dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i], dp[i-1][3]-prices[i])
            dp[i][1] = max(dp[i-1][1], dp[i-1][3])
            dp[i][2] = dp[i-1][0]+prices[i]
            dp[i][3] = dp[i-1][2]

            0 1 2
            s f 
            dp[0][0] = -prices[0], dp[0][1] = 0, dp[0][2] = 0, dp[0][3] = 0
        */
        vector<vector<int> > dp(prices.size(), vector<int>(4));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;
        for(int i=1;i<prices.size();i++){
            dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]-prices[i]), dp[i-1][3]-prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0]+prices[i];
            dp[i][3] = dp[i-1][2];
        }
        /*
        for(int i=0;i<prices.size();i++){
            cout<<"dp["<<i<<"]"<<"[0]:"<<dp[i][0]<<endl;
            cout<<"dp["<<i<<"]"<<"[1]:"<<dp[i][1]<<endl;
            cout<<"dp["<<i<<"]"<<"[2]:"<<dp[i][2]<<endl;
            cout<<"dp["<<i<<"]"<<"[3]:"<<dp[i][3]<<endl;
        }
        */
        return max(max(dp[prices.size()-1][1], dp[prices.size()-1][2]), dp[prices.size()-1][3]);
    }
};