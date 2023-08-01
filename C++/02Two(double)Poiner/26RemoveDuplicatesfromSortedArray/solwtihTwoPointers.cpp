class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
                          l
            nums = [1,3,2]
                          r  
        */
        int l = 1, r = 1;
        for(l,r;r<nums.size();){
            if(nums[r]!=nums[r-1]){
                nums[l] = nums[r];
                l++;
                r++;
            }
            else{
                r++;
            }
        }
        return l;
    }
};