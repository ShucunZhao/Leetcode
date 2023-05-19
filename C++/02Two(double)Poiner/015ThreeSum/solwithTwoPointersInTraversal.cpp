class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
                     i
                                 r   
                        l
            sort:   -4 -1 -1 0 1 2 
            nums = [-1,0,1,2,-1,-4]

            num[i] + nums[l] + nums[r] = 0
        */

        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) return ans;
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            int l = i+1, r = nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]>-nums[i]){
                    r--;
                }
                else if(nums[l]+nums[r]<-nums[i]){
                    l++;
                }
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    while(l<r&&nums[l+1]==nums[l]) l++;
                    while(l<r&&nums[r-1]==nums[r]) r--;
                    l++;
                    r--;
                }
            }
        }
        return ans;
    }
};