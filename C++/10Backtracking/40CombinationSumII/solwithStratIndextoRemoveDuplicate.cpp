class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    // set<vector<int> > st;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, int start){
        if(sum==target){
            ans.push_back(path);
            // st.insert(path);
            return;
        }
        for(int i = start;i<candidates.size()&&sum+candidates[i]<=target;i++){
            if(i>start&&candidates[i]==candidates[i-1]){//Just use start to remove the level duplicates, the depth duplicate sholdn't remove(it's valid)
                continue;
            }
            path.push_back(candidates[i]);
            sum+=candidates[i];
            backtracking(candidates, target, i+1);
            path.pop_back();
            sum-=candidates[i];
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        ans.clear();
        sort(candidates.begin(), candidates.end());
        backtracking(candidates,target,0);
        /*
        vector<int> newCan;
        for(int i=0;i<candidates.size()-1;i++){
            if(candidates[i]==candidates[i+1]){
                continue;
            }
            newCan.push_back(candidates[i]);
        }
        if(candidates[candidates.size()-1]!=candidates[candidates.size()-2]){
            newCan.push_back(candidates[candidates.size()-1]);
        } 
        backtracking(newCan,target,0);
        */
        /*
        //Use set to remove duplicates will cause tle!
        vector<vector<int> > ans;
        for(auto x : st){
            ans.push_back(x);
        }
        */
        return ans;
    }
};