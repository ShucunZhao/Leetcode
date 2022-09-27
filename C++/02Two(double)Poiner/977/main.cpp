class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        if(nums.size()==1){
            nums[0]= nums[0]*nums[0];
            return nums;
        }
        int size = nums.size();
        vector<int> ans(size, 0);
        int i = 0;
        int j = size-1;
        int k = size-1;
        while(i<=j){
            int iPow = nums[i]*nums[i];
            int jPow = nums[j]*nums[j];
            if(iPow>jPow){
                ans[k] = iPow;
                k--;
                i++;
            }
            else{
                ans[k] = jPow;
                k--;
                j--;
            }
        }
        return ans;
    }
};