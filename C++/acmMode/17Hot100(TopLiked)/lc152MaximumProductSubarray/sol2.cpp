class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            Input: nums = [2,3,-2,4]
                     max:  2 6
                     min:  2 
            Output: 6
            1.
                dp_max[i]: the max product of subarray in pos i
                dp_min[i]: the min product of subarray in pos i
            2.
                dp_max[i] = max(nums[i], max(nums[i]*dp_max[i-1], nums[i]*dp_min[i-1]))
                dp_min[i] = min(nums[i], min(nums[i]*dp_min[i-1], nums[i]*dp_max[i-1]))
            3. Record the temporary max value all the time.
        */
        vector<int> dp_max(nums.size(), 0);
        vector<int> dp_min(nums.size(), 0);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp_max[i] = max(nums[i], max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            dp_min[i] = min(nums[i], min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]));
            ans = max(dp_max[i], ans);
        }
        return ans;
    }
};