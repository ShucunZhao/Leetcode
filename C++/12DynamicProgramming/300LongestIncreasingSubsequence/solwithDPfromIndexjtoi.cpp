class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            ---------------------------------------
                                 j
                                    i
            nums = [4, 10, 4, 3, 8, 9] 
            dp:     1   2  1  1  2  3
            ans: 2

            dp[i]: the longest increasing subsequence in position i.
            Initialization: dp[x] = 1
            for(int i from 1 to nums.size()-1){
                for(int j=0;j<i;j++){
                    if(nums[i]>nums[j]){
                        dp[i] = max(dp[i], dp[j]+1);
                    }
                    ans = max(ans, dp[i]);
                }
            }
        */
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};