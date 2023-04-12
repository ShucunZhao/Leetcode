class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        /*
            dp[i][0]: do nothing in day i
            dp[i][1]: the first time hold in day i
            dp[i][2]: the first time unhold in day i
            dp[i][2]: the second time hold in day i
            dp[i][3]: the second time unhold in day i
            ......
            dp[i][k-1]: the k times hold in day i
            dp[i][k]: the k time unhold in day i

            dp[i][0] = dp[i-1][0]
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1])
            dp[i][2] = max(dp[i-1][1]+prices[i], dp[i-1][2])
            dp[i][odd] = max(dp[i-1][odd-1]-prices[i], dp[i-1][odd])
            dp[i][even] = max(dp[i-1][even-1]+prices[i], dp[i-1][even]);
            ......
            dp[i][k] = max(dp[i-1][k-1]-prices[i], dp[i-1][k]) if k is odd.
            dp[i][k] = max(dp[i-1][k-1]+prices[i], dp[i-1][k]) if k is even.
            ---->
            for(i from 0 to prices.size()){
                for(j from 0 to k){
                    if(j==0){
                        dp[i][j] = dp[i-1][j];
                    }
                    else if(j%2==1){
                        dp[i][j] = max(dp[i-1][j-1]-prices[i], dp[i-1][j]);
                    }
                    else if(j%2==0){
                        dp[i][j] = max(dp[i-1][j-1]+prices[i], dp[i-1][j]);
                    }
                }
            }
            Initialization:
            dp[0][0]: 0, dp[0][1] = -prices[0], dp[0][2] = 0;
            dp[0][odd]: -prices[0], dp[0][even]: 0 ... dp[0][k]: 0
        */
        vector<vector<int> > dp(prices.size(), vector<int>(2*k+1));
        for(int i=0;i<=2*k;i++){
            dp[0][i]=(i%2==0)?0:-prices[0];
        }
        //int ans = INT_MIN;
        for(int i=1;i<prices.size();i++){
            for(int j=0;j<=2*k;j++){
                if(j==0){
                    dp[i][0] = dp[i-1][0];
                }
                else if(j%2==1){
                    dp[i][j] = max(dp[i-1][j-1]-prices[i], dp[i-1][j]);
                }
                else if(j%2==0){
                    dp[i][j] = max(dp[i-1][j-1]+prices[i], dp[i-1][j]);
                }
                //ans = max(ans, dp[i][j]);
            }
        }
        /*
        for(int i=0;i<prices.size();i++){
            for(int j=0;j<=2*k;j++){
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
        */
        return dp[prices.size()-1][2*k];
        //return ans;
    }
};