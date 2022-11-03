class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(vector<int>& nums, int start){
        if(start==nums.size()) return;
        unordered_set<int> usedSet;//Use a hash set to record used elements to remove level-grade duplicates.
        for(int i = start;i<nums.size();i++){
            if(i>0&&usedSet.count(nums[i])>0){
                continue;
            }
            usedSet.insert(nums[i]);
            if(!path.empty()&&nums[i]<path.back()){
                continue;
            }
            path.push_back(nums[i]);
            if(path.size()>1){
                ans.push_back(path);
            }
            backtracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<bool> used(nums.size(), 0);
        backtracking(nums, 0);
        return ans;
    }
};