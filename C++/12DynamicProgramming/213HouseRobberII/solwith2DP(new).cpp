class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            nums = [2,3,2]
            dp[i]: the max we can rob in house i.
            There are two different initialization and traverse cases:
            1.choose the head rather than tail:
                i is from 0 to nums.size()-2:
                    dp[i] = max(dp[i-1], dp[i-2]+nums[i])
                    dp[0] = nums[0]
                    dp[1] = max(nums[0], nums[1])
            2.choose the tail rather than head:
                i is from 1 to nums.size()-1:
                    dp[i] = max(dp[i-1], dp[i-2]+nums[i])
                    dp[0] = nums[1]
                    dp[1] = max(nums[1], nums[2])                    
        */
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0], nums[1]);
        vector<int> dp1(nums.size()), dp2(nums.size());
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for(int i=2;i<nums.size()-1;i++){
            dp1[i] = max(dp1[i-1], dp1[i-2]+nums[i]);
        }
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);
        // nums = [1,2,3,1]
        for(int j=3;j<nums.size();j++){
            dp2[j] = max(dp2[j-1], dp2[j-2]+nums[j]);
        }        
        return max(dp1[nums.size()-2], dp2[nums.size()-1]);
    }
};