class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(vector<int> & nums, vector<bool> & used, int start){
        if(start==nums.size()) return;
        for(int i=start;i<nums.size();i++){
            if(i>0&&nums[i-1]==nums[i]&&!used[i-1]){
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            ans.push_back(path);
            backtracking(nums, used, i+1);
            path.pop_back();
            used[i] = false;
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.push_back({});
        vector<bool> used(nums.size(), false);
        backtracking(nums, used, 0);
        return ans;
    }
};