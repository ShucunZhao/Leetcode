/*
 * Never use the hash map in this question because it's hard to eliminate the repeated 
 * elements with hash map!
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //If you want use two pointer method, u need to sort the whole array at fist
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[0]>0){
                return {};
            }
            if(i>0&&nums[i-1]==nums[i]){
                continue;
            }
            for(int l = i+1,r=nums.size()-1;l<r;){
                if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0){         
                    l++;
                }
                else{
                    ans.push_back({nums[i],nums[l],nums[r]});
                    //Step for eliminating the repeat elements:
                    //You must save the result at first then do this step.
                    while(l<r&&nums[r-1]==nums[r]){
                        r--;
                    }
                    while(l<r&&nums[l+1]==nums[l]){
                        l++;
                    }
                    r--;
                    l++;
                }
            }
        }
        return ans;
    }
};