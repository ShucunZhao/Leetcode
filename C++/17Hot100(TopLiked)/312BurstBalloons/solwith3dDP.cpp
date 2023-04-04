class Solution {
public:
    int maxCoins(vector<int>& nums) {
        /*
            nums = [3,1,5,8]
            dp[i][j]: Burst ballons from i to j which length is "j-i+1" that the max coins we can get where the ballon we burst at last is k. 
            n = nums.size() = 4;
            dp:j:    0  1  2  3
               i: 0 
                  1
                  2
                  3  
            dp[i][j] = max(dp[i][j], leftVal*nums[k]*rightVal + partL + partR);
        */
        int left, right, partL, partR;
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), INT_MIN));
        for(int len=1;len<=nums.size();len++){
            for(int i=0;i<=nums.size()-len;i++){
                int j = len+i-1;
                for(int k=i;k<=j;k++){
                    left = i==0 ? 1 : nums[i-1];
                    right = j==nums.size()-1 ? 1 : nums[j+1];
                    partL = i==k ? 0 : dp[i][k-1];
                    partR = j==k ? 0 : dp[k+1][j];
                    dp[i][j] = max(dp[i][j], left*nums[k]*right+partL+partR);
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};