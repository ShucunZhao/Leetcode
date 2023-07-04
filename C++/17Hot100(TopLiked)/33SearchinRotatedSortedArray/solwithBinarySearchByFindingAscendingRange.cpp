class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if(size==1&&nums[0]==target) return 0;
        /* 
            Step1: Use binary search to find the middle pointer.
            Step2: According to the mid pointer to divide the array into left and right parts,
                   and these two part must one is ascending array another is mix array.
            Step3: Determine which part is the ascending part by comparing the mid value with the left-most or right-most value,
                   if nums[mid]<nums[right] means the array from mid to right is ascending.
            Step4: Determin if the target value is in the ascending array: 
                    if yes, move the pointer to shrink the range of ascending array.
                    else move the pointer to shrink the mix range and do the steps above again.
                     
            target: 2
                      
                    l           r 
            nums = [6,7,8,1,2,4,5]
                          m

                    l     r
            nums = [5, 1, 3]
                       m
            t: 5          
        */
        int l = 0, r = size-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m]==target) return m;
            if(nums[m]<nums[r]){//If the right part is ascending array, we determine if the target is inside of it.
                if(target>nums[m]&&target<=nums[r]){
                    l=m+1;
                }
                else{
                    r=m-1;
                }
            }
            else{
                if(target<nums[m]&&target>=nums[l]){
                    r = m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        return -1;
    }
};