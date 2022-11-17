class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=1;j<=coins.size();j++){
                if(coins[j-1]<=i&&dp[i-coins[j-1]]!=-1){
                    if(dp[i]==-1||dp[i]>(dp[i-coins[j-1]]+1)){
                        dp[i] = dp[i-coins[j-1]]+1;
                    }
                }
            }
        }
        // for(int i=0;i<=amount;i++){
        //     cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
        // }
        return dp[amount];
    }
};