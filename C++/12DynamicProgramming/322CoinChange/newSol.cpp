class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i&&dp[i-coins[j]]!=-1){//If i larger than conins[j], judge if coins[j] can choose (which means "dp[i-coins[j]]" should be calculated, dp[i-coins[j]] shouldn't be -1). 
                    if(dp[i]==-1) dp[i] = dp[i-coins[j]]+1;//If dp[i] has not been calculate let it be dp[i-coins[j]]+1
                    else dp[i] = min(dp[i], dp[i-coins[j]]+1);//Else choose the smaller one when try 0-coins.size of coins.
                }
            }
        }
        // for(int i=0;i<=amount;i++){
        //     cout<<"dp["<<i<<"]:"<<dp[i]<<endl;
        // }
        return dp[amount];
    }
};