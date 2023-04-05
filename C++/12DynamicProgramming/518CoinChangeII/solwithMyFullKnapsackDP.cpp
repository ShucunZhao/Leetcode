class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*
           full knapack problem:
           dp[i][j]: the times that choose objs from the first i objects to fill the knapsack 
           whose size is j exactly where the obj can be used infinitely.
           if(coins[i]>j){
               dp[i][j] = dp[i-1][j];
           }
           else{
               dp[i][j] = dp[i-1][j]+dp[i][j-coins[i]];(dp[i-1][j] is don't take current obj situation, and
                                                        dp[i][j-coins[i] is take current obj)
           }
           Initialization: 
                When our target amount is 0, whatever what we choose the scheme is only 1, so:
                dp[x][0] = 1
           coins = [1,2,5] , amount = 5
               size: 0 1 2 3 4 5  
           obj:  1   0 1 1 1 1 1
                 2   0 1 2 2 3 3
                 5   0 1 2 2 3 

        */
        vector<vector<int> > dp(coins.size(), vector<int>(amount+1,0));
        for(int i=0;i<coins.size();i++){
            dp[i][0] = 1;
        }
        for(int j=1;j<=amount;j++){
            if(j>=coins[0]&&j%coins[0]==0){
                dp[0][j] = 1;
            }
        }
        /*
        for(int i=0;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
        */
        for(int i=1;i<coins.size();i++){
            for(int j=1;j<=amount;j++){
                if(coins[i]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i]];
                }
            }
        }
        return dp[coins.size()-1][amount];
    }
};