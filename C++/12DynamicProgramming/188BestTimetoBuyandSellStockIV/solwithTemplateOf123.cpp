/*
 * This problem is tempalate the question 123:
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int m = prices.size();
        int n = 2*k + 1;
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            if(i%2==1){
                dp[0][i] = -prices[0];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp[i][j] = dp[i-1][0];
                }
                else if(j%2==1){
                    dp[i][j] = max(dp[i-1][j-1]-prices[i], dp[i-1][j]);
                }
                else if(j%2==0){
                    dp[i][j] = max(dp[i-1][j-1]+prices[i], dp[i-1][j]);
                }
            }
        }
        return dp[m-1][n-1];
    }
};