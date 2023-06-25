class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(vector<int> & nums, vector<bool> & used, int start){
        if(start==nums.size()){
            return;
        }
        // unordered_set<int> mset;
        vector<bool> used2(200, false);
        for(int i=start;i<nums.size();i++){
            // if(mset.count(nums[i])) continue;
            if(used2[nums[i]+100]) continue;
            if(i>0&&nums[i-1]==nums[i]&&!used[i-1]){
                continue;
            }
            if(path.empty()||path.back()<=nums[i]){
                // mset.insert(nums[i]);
                used2[nums[i]+100] = true;
                path.push_back(nums[i]);
                used[i] = true;
                if(path.size()>1){
                    ans.push_back(path);
                }
                backtracking(nums, used, i+1);
                path.pop_back();
                used[i] = false;
            } 
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used, 0);
        return ans;
    }
};