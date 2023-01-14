class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        //nums =       [1,3,5,4,7]
        //dp:(Init)     1 1 1 1 1
        //dp:(Iterate)    2 3 
        if(nums.size()<2) return 1;
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        int maxL = INT_MIN;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(dp[i]<dp[j]+1){
                        count[i] = count[j];
                    }
                    else if(dp[i]==dp[j]+1){
                        count[i]+=count[j];
                    }
                    dp[i] = max(dp[i], dp[j]+1);
                }
                maxL = max(dp[i], maxL);
            }
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(dp[i]==maxL) ans+=count[i];
        }
        return ans;
    }
};