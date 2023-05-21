class Solution {
public:
    int jumpFloorII(int number) {
        /*
            dp[i]: the number of ways to get to step i.
            dp[0]: 0
            dp[1]: 1
            dp[2]: 2
            dp[3]: 4
            dp[4]: 8
            1 1 1 1
            1 2 1
            1 1 2
            2 1 1
            2 2
            1 3
            3 1
            4 
            dp[i] = sum(dp[0, i-1]) + 1;
        */
        if(number<3) return number; 
        vector<int> dp(number+1);
        vector<int> sum(number+1);
        dp[0] = 0;
        sum[0] = 0;
        dp[1] = 1;
        sum[1] = sum[0]+dp[1];
        dp[2] = 2;
        sum[2] = sum[1]+dp[2];
        for(int i=3;i<=number;i++){
            dp[i] = sum[i-1] + 1;
            sum[i] = dp[i] + sum[i-1];
        }
        return dp[number];
    }
};