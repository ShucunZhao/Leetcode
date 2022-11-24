class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()<2) return nums[0]; 
        int l=0, r=nums.size()-1;
        int m;
        while(l<=r){
            m = l+(r-l)/2;
            if(m==0){
                if(nums[m]!=nums[m+1]){
                    return nums[m];
                }
                else{
                    l = m+1;
                }
            }
            else if(m==nums.size()-1){
                if(nums[m]!=nums[m-1]){
                    return nums[m];
                }
                else{
                    r = m-1;
                }
            }
            else if(m%2==0){
                if(nums[m-1]==nums[m]&&nums[m]!=nums[m+1]){
                    r=m-1;
                }
                else if(nums[m]==nums[m+1]){
                    l = m+1;
                }
                else if(nums[m]!=nums[m+1]&&nums[m-1]!=nums[m]){
                    return nums[m];
                }
            }
            else if(m%2==1){
                if(nums[m-1]==nums[m]&&nums[m]!=nums[m+1]){
                    l = m+1;
                }
                else if(nums[m]==nums[m+1]){
                    r = m-1;
                }
                else if(nums[m]!=nums[m+1]&&nums[m-1]!=nums[m]){
                    return nums[m];
                }
            }
        }
        return -1;
    }
};