class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        int sum = nums[0];
        int ans = sum;
        for(int i=1;i<nums.size();i++){
            if(sum<0){
                sum = nums[i];
            }
            else{
                sum+=nums[i];
            }
            ans = max(sum, ans);
        }
        return ans;
    }
};