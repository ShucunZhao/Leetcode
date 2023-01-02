class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size()<2) return 0;
        vector<vector<int> > dp(prices.size(), vector<int>(2*k+1, 0));
        /* The key is total states is 2*k + 1
        dp[0][0]: 0; non-operation
        dp[0][1]: -prices[0]; first hold
        dp[0][2]: 0; first unhold
        dp[0][3]: -prices[0]; second hold
        dp[0][4]: 0; second unhold
        dp[0][odd i in k]: -prices[0]; xx times hold;
        dp[0][even i in k]: 0; xx+1 times unhold;
        */
        int ans = 0;
        dp[0][0] = 0;
        for(int i=0;i<2*k+1;i++){
            if(i%2==1) dp[0][i] = -prices[0];
        }
        for(int i=1;i<prices.size();i++){
            dp[i][0] = dp[i-1][0];
            for(int j=1;j<2*k+1;j++){
                if(j%2==1){
                    // dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]-prices[i]);
                }
                else{
                    // dp[i][2] = max(dp[i-1][2], dp[i-1][1]+prices[i]);
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+prices[i]);
                    ans = max(dp[i][j], ans);
                }
            }
        }
        // for(int i=0;i<prices.size();i++){
        //     for(int j=0;j<2*k+1;j++){
        //         cout<<"dp["<<i<<"]"<<"["<<j<<"]:"<<dp[i][j]<<endl;
        //     }
        // }
        return ans;
    }
};