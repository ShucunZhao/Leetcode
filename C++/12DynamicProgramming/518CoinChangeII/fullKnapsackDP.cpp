/* Fully knapsack question:
 *I. dp[i][j]: The maximum value of the first i objects can full fill a knapsack
               whose size is j exactly.
 *II.Inference formula: If nums[i] > j: dp[i][j] = dp[i-1][j]
                        else dp[i][j] = max(dp[i-1][j], dp[i][j-nums[i]]+nums[i]) -- Diff with 01 knapsack here:
                                                                                     should cmp with current i.
 *III.Initialization: dp[0][0] = 1 (Because 0 can fill size 0.)
                      dp[0][...] = 0
                      dp[...][0] = 0
 *IV.Iterator order: From front to back
 *V. Print the dp array to debug
 */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int> > dp(coins.size()+1, vector<int>(amount+1,0));
        dp[0][0] = 1;
        for(int i=1;i<=coins.size();i++){
            for(int j=0;j<=amount;j++){
                dp[i][j] = dp[i-1][j];
                if(coins[i-1]<=j){
                    dp[i][j] += dp[i][j-coins[i-1]]; 
                }
            }
        }
        // for(int i=0;i<=coins.size();i++){
        //     for(int j=0;j<=amount;j++){
        //         cout<<"dp["<<i<<"]"<<"["<<j<<"]:"<<dp[i][j]<<endl;
        //     }
        // }
        return dp[coins.size()][amount];
    }
};