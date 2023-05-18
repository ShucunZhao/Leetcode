class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool isLeft){
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]>target){
                r = m-1;
            }
            else if(nums[m]<target){
                l = m+1;
            }
            else{
                if(isLeft){
                    if(m==0||(nums[m-1]<nums[m])) return m;
                    else{
                        r = m-1;
                    }
                }
                else{
                    if(m==nums.size()-1||(nums[m+1]>nums[m])) return m;
                    else{
                        l = m+1;
                    }
                }
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {binarySearch(nums, target, true), binarySearch(nums, target, false)};
    }
};