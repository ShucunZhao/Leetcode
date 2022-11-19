class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {  
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                dp[i] = dp[i-1]+1;
            }
            // ans = max(ans, dp[i]);
            ans = ans > dp[i] ? ans : dp[i];
            // if(ans<dp[i]) ans = dp[i];
        }
        return ans;
    }
};