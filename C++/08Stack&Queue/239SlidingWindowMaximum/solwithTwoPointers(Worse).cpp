class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<int, int> ms;//Use map as the sliding window because it has sorting key value function inside.
        vector<int> ans;
        for(int l=0,r=0;r<nums.size();r++){
            ms[nums[r]]++;
            if(r-l+1>=k){
                ans.push_back(ms.rbegin()->first);
                ms[nums[l]]--;
                if(ms[nums[l]]==0){
                    ms.erase(nums[l]);
                }
                l++;
            }
        }
        return ans;
    }
};