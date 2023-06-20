class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, int start){
        if(sum==target){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(sum>target){
                break;
            }
            // used[i] = true;
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            sum-=candidates[i];
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // vector<bool> used(candidates.size());
        backtracking(candidates, target, 0);
        return ans;
    }
};