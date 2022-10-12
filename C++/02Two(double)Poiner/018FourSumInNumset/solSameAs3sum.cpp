class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        if((nums[0]>=0&&nums[0]>target)||nums.size()<4){//Pruning step1.
            return {};
        }
        for(int i=0;i<nums.size()-3;i++){
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            for(int j=i+1;j<nums.size()-2;j++){
                if(j>i+1&&nums[j-1]==nums[j]){
                    continue;
                }
                if(nums[i]+nums[j]>target&&target>0){//Pruning step2.
                    continue;
                }
                for(int l=j+1,r=nums.size()-1;l<r;){
                    if((long)nums[i]+nums[j]+nums[l]+nums[r]>target){
                        r--;
                    }
                    else if((long)nums[i]+nums[j]+nums[l]+nums[r]<target){
                        l++;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        while(l<r&&nums[r-1]==nums[r]){
                            r--;
                        }
                        while(l<r&&nums[l+1]==nums[l]){
                            l++;
                        }
                        l++;
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};