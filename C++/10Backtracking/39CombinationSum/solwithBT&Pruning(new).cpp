class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(int sum, int target, vector<int> & candidates, int start){
        if(sum==target){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<candidates.size()&&(sum+candidates[i]<=target);i++){
            // if(sum+candidates[i]>target){
            //     continue;
            // }
            path.push_back(candidates[i]);
            sum+=candidates[i];
            backtracking(sum, target, candidates, i);
            path.pop_back();
            sum-=candidates[i];
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /*
            candidates =    [2,3,6,7], target = 7
                         2   
              2      3
         2   3    2 
   2       


        */
        sort(candidates.begin(), candidates.end());
        backtracking(0, target, candidates, 0);
        return ans;
    }
};