class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        /*
                             i
            nums = [1, 3, 5, 4, 7]
            dp:     1  2  3  1  1
            ans: 1 

            Initialization:
                dp[x] = 1;
            ans = 1
            for(int i from 1 to nums.size()){
                if(nums[i]>nums[i-1]){
                    dp[i] = dp[i-1]+1;
                }
                else{
                    dp[i] = 1;
                }
                ans = max(dp[i], ans);
            }
        */
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                dp[i] = dp[i-1]+1;
            }
            else{
                dp[i] = 1;
            }
            // cout<<dp[i]<<endl;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};