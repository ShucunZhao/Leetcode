class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=1,r=1;
        for(l,r;r<nums.size();r++){
            if(nums[r]!=nums[r-1]){
                nums[l] = nums[r];
                l++;
            }
        }
        return l;
    }
};