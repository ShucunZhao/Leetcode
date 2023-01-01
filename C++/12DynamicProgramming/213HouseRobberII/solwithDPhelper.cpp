class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        int case1 = helper(nums, 1, nums.size());
        int case2 = helper(nums, 0, nums.size()-1);
        return max(case1, case2);
        // return case1>case2?case1:case2;
    }
    int helper(vector<int>& nums, int start, int end){
        if(start>=end-1) return nums[start];
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for(int i=start+2;i<end;i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
            cout<<"dp["<<i<<"]:"<<dp[i]<<endl;
        }
        return dp[end-1];
    }
};