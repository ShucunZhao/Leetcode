class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(int n, int k, int start){
        if(path.size()==k){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<=n;i++){
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return ans;
    }
};