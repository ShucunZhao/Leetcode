class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /*
            nums = [-2,   3,   -4   4]      MA:-2,3,24            MI:-2,-6,-12
            dpMax   -2    3    24
            dpMin   -2   -6    -12
        */
        vector<int> dpMax(nums.size());
        vector<int> dpMin(nums.size());
        dpMax[0] = dpMin[0] = nums[0];//0
        int ans = nums[0];//0
        for(int i=1;i<nums.size();i++){
            dpMax[i] = max(max(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i]), nums[i]);
            dpMin[i] = min(min(dpMax[i-1]*nums[i], dpMin[i-1]*nums[i]), nums[i]);
            ans = max(dpMax[i], ans);
        }
        return ans;
    }
};