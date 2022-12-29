class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2==1) return 0;
        int target = sum/2;
        vector<vector<bool> > dp(nums.size(), vector<bool>(target+1, 0));
        if(target>=nums[0]){
            dp[0][nums[0]] = 1;
        }
        // dp[0][nums[0]] = 1;//Must prevent overflow here!
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=target;j++){//Because nums[i] is >= 1;
                if(j<nums[i]){
                    dp[i][j] = dp[i-1][j];
                }
                else if(j>nums[i]){
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-nums[i]];
                }
                else{
                    dp[i][j] = 1;
                }
            }
        }
        return dp[nums.size()-1][target];
    }
};