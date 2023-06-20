class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    int sum = 0;
    void backtracking(vector<int>& candidates, vector<bool> & used, int target, int start){
        if(sum==target){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>0&&candidates[i-1]==candidates[i]&&!used[i-1]){
                continue;
            }
            if(sum>target){
                break;
            }
            used[i] = true;
            sum+=candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, used, target, i+1);
            sum-=candidates[i];
            path.pop_back();
            used[i] = false;
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size());
        backtracking(candidates, used, target, 0);
        return ans;
    }
};