/*
 * Because the maximum element will show in head or tail so that let two pointers left and right endpoint to move to middle.
 */
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int l=0,r=nums.size()-1;
        int k = r;
        for(l,r;l<=r;){
            int left = nums[l]*nums[l];
            int right = nums[r]*nums[r];
            if(left>right){
                ans[k] = left;
                l++;
                k--;
            }
            else{
                ans[k] = right;
                r--;
                k--;
            }
        }
        return ans;
    }
};