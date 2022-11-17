class Solution {
public:
    int climbStairs(int n) {
        // int nums[2] = {1,2};
        int m = 2;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //if(nums[j-1]<=i){
                if(j<=i){
                    dp[i]+=dp[i-j];
                }
            }
        }
        return dp[n];
    }
};