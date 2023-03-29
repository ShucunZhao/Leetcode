class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*
            stones = [2,7,4,1,8,1]
            sum = 23
            half(-) = 11,    half(+) = 12
            Find the max weight that choose goods from stones to fill
            the knapsack whose size is half(-).
            dp[i][j]: the max goods weight we can load to  knapsack when choose 
            the first i goods to fill it and whose size is half(-).

        good: size: 0 1 2 3 4 5 6 7 8 9 10 11     
            2       0 0 2 2 2 2 2 2 2 2  2  2
            7
            4
            1
            8
            1
            dp[0][x] = stones[0](x is >= stones[0]);
            dp[i][j]: (i from 1 to stones.size(), j from 1 to half)
                if(stones[i]>j){
                    dp[i][j] = dp[i-1][j]
                }
                else{
                    dp[i][j] = max(dp[i-1][j], stones[i]+dp[i-1][j-stones[i]]);
                }
        */
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int half = sum/2;//This is half(-).
        vector<vector<int> > dp(stones.size(), vector<int>(half+1, 0));
        for(int j=0;j<=half;j++){
            if(j>=stones[0]){
                dp[0][j] = stones[0];
            }
        }
        for(int i=1;i<stones.size();i++){
            for(int j=0;j<=half;j++){
                if(stones[i]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], stones[i]+dp[i-1][j-stones[i]]);
                }
            }
        }
        return sum - 2*dp[stones.size()-1][half];
    }
};