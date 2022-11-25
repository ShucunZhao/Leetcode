class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0;
        for(l,r;r<nums.size();r++){
            if(nums[r]!=0){
                nums[l] = nums[r];
                l++;
            }
        }
        for(l;l<nums.size();l++){
            nums[l] = 0;
        }
    }
};