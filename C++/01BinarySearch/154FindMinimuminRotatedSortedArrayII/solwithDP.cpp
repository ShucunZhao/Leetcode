class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()<2) return nums[0];
        int l = 0, r = nums.size()-1;
        while(l<r&&nums[l]==nums[r]){//Need to clean the left duplicates at first then use the binary search.
            l++;
        }
        if(nums[l]<nums[nums.size()-1]) return nums[l];
        int m;
        while(l<=r){
            m = l+(r-l)/2;
            if(m!=0&&(m!=nums.size()-1)&&nums[m-1]>nums[m]&&nums[m+1]>nums[m]) return nums[m];
            else if(nums[m]<=nums[nums.size()-1]){//KeyPoint:  Each time you find the edge case has something different answer you should change
                                                 //the judge condition.
                r = m-1;
            }
            else if(nums[m]>nums[nums.size()-1]){
                l = m+1;
            }
        }
        return nums[l];
    }
};