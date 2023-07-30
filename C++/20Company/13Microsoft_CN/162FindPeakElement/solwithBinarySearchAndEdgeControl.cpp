class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int size = nums.size();
        if(size==1) return 0;
        int l = 0, r = size-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(m==size-1&&nums[m]>nums[m-1]){
                return m;
            }
            else if(m==0&&nums[m]>nums[m+1]){
                return m;
            }
            else if(m==size-1||nums[m+1]>nums[m]){
                l = m+1;
            }
            else if(m==0||nums[m-1]>nums[m]){
                r = m-1;
            }
            else if(nums[m]>nums[m+1]&&nums[m]>nums[m-1]){
                return m;
            }
        }
        return -1;
    }
};