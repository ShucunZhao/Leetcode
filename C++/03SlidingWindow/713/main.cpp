/*
 * The task is a little bit different from the traditonal sliding window problem:
 * There is a situation where the left pointer can larger than the right one:
 * In this case, the number of interval is r-l+1 = 0, which is also valid.
 * And the product at this time is resume the inital value 1.
 */
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0){
            return 0;
        }
        int ans=0,pro=1;
        for(int l=0,r=0;r<nums.size();r++){
            pro*=nums[r];
            while(l<=r&&pro>=k){//Key point here: l can be equal to r.
                pro/=nums[l];
                l++;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};