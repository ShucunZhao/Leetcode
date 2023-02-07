class Solution {
public:
    int binarySearch(vector<int> & nums, int target, bool left){
        int l=0, r=nums.size()-1;
        int m;
        while(l<=r){
            m = l+(r-l)/2;
            if(nums[m]>target){
                r = m-1;
            }
            else if(nums[m]<target){
                l = m+1;
            }
            else{
                if(left){
                    if(m==0) return m;
                    while(m!=0&&nums[m-1]==target) m-=1;
                    return m;
                }
                else{
                    if(m==nums.size()-1) return m;
                    while(m!=nums.size()-1&&nums[m+1]==target) m+=1;
                    return m;
                }
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
              i:    0 1 2 3 4 5
            nums = [5,7,7,8,8,10], target = 8
                    l   m   m  r
                          l
            if(nums[m]==tar&&(m==size-1||nums[m+1]>target)){
                r = m;
            } 
        */
        return {binarySearch(nums,target,1), binarySearch(nums,target,0)};
    }
};