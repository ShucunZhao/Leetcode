class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
                       i
                         j
                               k
                      -2 0 1 1 2           
             sort:   -4,-1,-1,0,1,2
             nums = [-1,0,1,2,-1,-4]
             ans: 
        */   
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]>0) return ans;
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            for(int j=i+1;j<nums.size()-1;j++){
                if(j>i+1&&nums[j-1]==nums[j]){
                    continue;
                }
                for(int k=j+1;k<nums.size();k++){
                    if(k>j+1&&nums[k-1]==nums[k]){
                        continue;
                    }
                    if(nums[i]+nums[j]+nums[k]==0){
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }
        return ans;
    }
};