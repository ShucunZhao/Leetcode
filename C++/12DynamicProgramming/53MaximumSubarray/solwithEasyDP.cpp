class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
            nums = [-2,1,-3,4,-1,2,1,-5,4]
            dp:     -2 1 -2 4  3 5 6  1 5 

             nums = [5,4,-1,7,8]
             dp      5 9  8 1523 
             max: 9
            dp[i] = max(dp[i-1]+nums[i], nums[i])
        */   
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ans = dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};