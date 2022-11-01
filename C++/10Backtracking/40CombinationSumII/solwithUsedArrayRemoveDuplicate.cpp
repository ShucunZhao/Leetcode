class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    // set<vector<int> > st;
    int sum = 0;
    void backtracking(vector<int>& candidates, int target, int start, vector<bool> & used){
        if(sum==target){
            ans.push_back(path);
            // st.insert(path);
            return;
        }
        for(int i = start;i<candidates.size()&&sum+candidates[i]<=target;i++){
            if(i>0&&used[i-1]==0&&candidates[i]==candidates[i-1]){
                continue;
            }
            used[i]=1;
            path.push_back(candidates[i]);
            sum+=candidates[i];
            backtracking(candidates, target, i+1, used);
            path.pop_back();
            sum-=candidates[i];
            used[i]=0;
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        ans.clear();
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), 0);
        backtracking(candidates,target,0,used);

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