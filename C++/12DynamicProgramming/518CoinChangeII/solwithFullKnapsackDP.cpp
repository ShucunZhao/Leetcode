class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
           full knapack problem:
           dp[i][j]: the times that choose objs from the first i objects to fill the knapsack 
           whose size is j exactly where the obj can be used infinitely.
           if(coins[i-1]>j){
               dp[i][j] = dp[i-1][j];
           }
           else{
               dp[i][j] = max(dp[i-1][j], dp[i][j-coins[i]])+1;
           }
           coins = [1,2,5] , amount = 5
               size: 0 1 2 3 4 5  
           obj:  1   1 1 1 1 1 1
                 2   1 1 2 2 3 3
                 5   1 1 2 2 3 

        */
        vector<vector<int> > dp(coins.size()+1, vector<int>(amount+1,0));
        for(int i=1;i<=coins.size();i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[coins.size()][amount];
    }
};