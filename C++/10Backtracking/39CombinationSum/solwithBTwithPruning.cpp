class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    int sum = 0;
    int flag = 0;
    void backtracking(vector<int>& candidates, int target, int start){
        if(sum>target) {
            flag = 1;
            return;
        }
        if(sum==target){
            ans.push_back(path);
            return;
        }
        for(int i = start;i<candidates.size()&&!flag;i++){
            path.push_back(candidates[i]);
            sum+=candidates[i];
            backtracking(candidates, target, i);
            /*
            if(sum>target){//Cannot just break/return here because if only break it will conitue running the next i for loop
                sum-=candidates[i];
                path.pop_back();
                break;
            }
            */
            sum-=candidates[i];
            path.pop_back();
        }
        flag = 0;
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0);
        return ans;
    }
};