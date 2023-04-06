class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
            dp[i]: the minimum numbers of coins to fill the amount.
            dp[i]=min(dp[i-coins[i]]+1  (i>=coins[i])
            Initialization:
            dp[0] = 0;
            dp[coins[i]] = 1;
        */
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        sort(coins.begin(), coins.end());
        for(int i=0;i<coins.size();i++){
            if(coins[i]<=amount){
                dp[coins[i]] = 1;
            }
        }
        /*
        for(int i : dp){
            cout<<i<<",";
        }
        cout<<endl;
        */
        /*
            i:  0  1  2  3  4 5  6  7  8  9 10 11
            dp: 0, 1, 1,-1,-1,1,-1,-1,-1,-1,-1,-1,
        */
        for(int i=0;i<=amount;i++){//2
            for(int j=0;j<coins.size();j++){//coins: 1,2,5
                if(i>=coins[j]){
                    if(dp[i-coins[j]]!=-1){
                        if(dp[i]!=-1){
                            dp[i] = min(dp[i], dp[i-coins[j]]+1);
                        }
                        else{
                            dp[i] = dp[i-coins[j]]+1;
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
        
        return dp[amount];
    }
};