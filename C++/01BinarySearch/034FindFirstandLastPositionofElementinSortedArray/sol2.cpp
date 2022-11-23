class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==1&&nums[0]==target){
            return {0,0};
        }
        int l = 0, r = nums.size();
        return {findPos(l,r,nums,target,0), findPos(l,r,nums,target,1)};
    }
    int findPos(int l, int r, vector<int> & nums, int target, bool pos){
        int m;
        while(l<r){
            m = l+(r-l)/2;
            if(nums[m]>target){
                r = m;
            }
            else if(nums[m]<target){
                l = m+1;
            }
            else{
                if(!pos){
                    if(m==0) return m;
                    if(nums[m-1]==nums[m]){
                        r = m;
                    }
                    else{
                       return m; 
                    }
                }
                else{
                    if(m==nums.size()-1) return m;
                    if(nums[m+1]==nums[m]){
                        l=m+1;
                    }
                    else{
                        return m;
                    }
                }
            }
        }        
        return -1;
    }
};