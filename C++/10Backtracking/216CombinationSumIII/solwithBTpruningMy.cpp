class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    int sum = 0;
    int flag = 0;//Used for pruning.
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
        path.clear();
        backtracking(k, n, 1);
        return ans;
    }
    void backtracking(int k, int n, int start){
        if(path.size()==k){
            if(sum==n){
                ans.push_back(path);
            }
            return;
        }
        for(int i=start;(i<=9-(k-path.size())+1)&&(!flag);i++){
            path.push_back(i);
            sum+=i;
            backtracking(k,n,i+1);
            if(sum>=n){
                flag == 1;
            }
            sum-=i;
            path.pop_back();
        }
        flag = 0;
        return;
    }
};