class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(vector<int> & nums, vector<bool> & used, int start){
        if(start==nums.size()){
            return;
        }
        unordered_set<int> Set;
        for(int i=start;i<nums.size();i++){
            if(!path.empty()&&nums[i]<path.back()){
                continue;
            }
            if(i>0&&nums[i]==nums[i-1]&&!used[i-1]){
                continue;
            }
            if(Set.count(nums[i])){
                continue;
            }
            Set.insert(nums[i]);
            used[i] = 1;
            path.push_back(nums[i]);
            if(path.size()>=2){
                ans.push_back(path);
            }
            backtracking(nums, used, i+1);
            path.pop_back();
            used[i] = 0;
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        /*
            Use the used array to remove the tree duplicates in traversal, 
            ans use hash set to remove the level duplicates in for loop in 
            each traversal level.
        */
        vector<bool> used(nums.size(), 0);
        backtracking(nums, used, 0);
        return ans;
    }
};