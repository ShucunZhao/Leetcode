/*
 * You need to analyze the different situations and compare to the most right element.
 */
class Solution {
public:
    int findMin(vector<int>& nums){
        if(nums.size()<2||nums[0]<nums[nums.size()-1]) return nums[0];
        int l=0,r=nums.size()-1;
        int m;
        while(l<=r){
            m = l+(r-l)/2;
            if(m!=0&&(m!=nums.size()-1)&&nums[m-1]>nums[m]&&nums[m]<nums[m+1]){
                return nums[m];
            }
            else if(nums[m]>nums[nums.size()-1]){
                l = m+1;
            }
            else if(nums[m]<=nums[nums.size()-1]){
                r = m-1;
            }
        }
        return nums[l];
    }
};