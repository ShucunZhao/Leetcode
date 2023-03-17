class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(int sum, int target, vector<int> & candidates, int start, vector<bool> & used){
        if(sum==target){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size()&&(sum+candidates[i]<=target);i++){
            if(i>0&&candidates[i]==candidates[i-1]&&!used[i-1]){
                continue;
            }
            used[i] = 1;
            path.push_back(candidates[i]);
            sum+=candidates[i];
            backtracking(sum, target, candidates, i+1, used);
            path.pop_back();
            sum-=candidates[i];
            used[i] = 0;
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*
                [1,1,2,5,6,7,10]
            1
        
        */
        vector<bool> used(candidates.size(), 0);
        sort(candidates.begin(), candidates.end());
        backtracking(0, target, candidates, 0, used);
        return ans;
    }
};