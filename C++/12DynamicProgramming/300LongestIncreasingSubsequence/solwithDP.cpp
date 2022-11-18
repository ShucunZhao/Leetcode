class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i], dp[j]+1);
                }
            }
            ans = ans>dp[i]?ans:dp[i];
        }
        // for(auto i : dp){
        //     cout<<i<<endl;
        // }
        return ans;
    }
};