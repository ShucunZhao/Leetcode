class Solution {
public:
    int rectCover(int number) {
        /*
            dp[i]: the different ways can construct the large rectangle when width is i.
            dp[0] = 0
            dp[1] = 1
            dp[2] = 2
            dp[3] = 3
            dp[4] = 5
            dp[i] = dp[i-1]+dp[i-2]
        */
        if(number==0) return 0;
        vector<int> dp(number+1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3;i<=number;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[number];
    }
};