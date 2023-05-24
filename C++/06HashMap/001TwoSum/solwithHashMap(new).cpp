class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ms;
        for(int i=0;i<nums.size();i++){
            if(ms.count(target-nums[i])){
                return {ms[target-nums[i]], i};
            }
            ms[nums[i]] = i;
        }
        return {};
    }
};