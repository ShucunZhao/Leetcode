class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
              i:    0 1 2 3 4 5 6
            nums = [1,2,1,3,5,6,4]
        */
        int size = nums.size();
        if(size==1) return 0;
        int l = 0, r = size-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if((m==0&&nums[m]>nums[m+1])||(m==size-1&&nums[m]>nums[m-1])){
                return m;
            }
            else if(m>0&&m<size-1&&(nums[m]>nums[m+1]&&nums[m]>nums[m-1])){
                return m;
            }
            else if(m==size-1||m<size-1&&nums[m]<=nums[m+1]){
                r = m-1;
            }
            else if(m==0||m>0&&nums[m-1]>nums[m]){
                l = m+1;
            }
        }
        l = 0, r = size-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if((m==0&&nums[m]>nums[m+1])||(m==size-1&&nums[m]>nums[m-1])){
                return m;
            }
            else if(m>0&&m<size-1&&(nums[m]>nums[m+1]&&nums[m]>nums[m-1])){
                return m;
            }
            else if(m==0||m<size-1&&nums[m]<=nums[m+1]){
                l = m+1;
            }
            else if(m==size-1||m>0&&nums[m-1]>nums[m]){
                r = m-1;
            }
        }        
        return -1;
    }
};