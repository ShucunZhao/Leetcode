class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        /*
            cnt:  1
            maxL: 3
            i:      0 1 2 3 4
            nums = [1,3,5,4,7]
            dp:     1 2 3 3 4

            dp[i]: the length of longest increasing subsequence in pos i. 
            Initialization:
                dp[i] = 1.
            Infer formula:
                if(nums[i]>nums[j]){
                    max(dp[j]+1, dp[i])//the j is from 0 to i-1.
                }
        */
        vector<int> dp(nums.size(),1);
        vector<int> cnt(nums.size(), 1);
        int maxL = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[j]+1>dp[i]){
                        cnt[i] = cnt[j];
                    }
                    else if(dp[j]+1==dp[i]){
                        cnt[i]+=cnt[j];
                    }
                    dp[i] = max(dp[i], dp[j]+1);
                }
                maxL = max(dp[i], maxL);
            }
        }
        /*
        for(int i : dp){
            cout<<i<<endl;
        }
        */
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxL) ans+=cnt[i];
        }
        return ans;
    }
};