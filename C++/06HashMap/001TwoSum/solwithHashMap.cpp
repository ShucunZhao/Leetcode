class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ms;//Use the hash map to record the elements have already showed.
        int find;
        for(int l=0;l<nums.size();l++){
            find = target - nums[l];
            if(ms.count(find)==0){//If not find, add it into map
                ms[nums[l]]=l;
            }
            else{//If find the other target, return the ans.
                return {ms[find],l};
            }
        }
        return {};
    }
};