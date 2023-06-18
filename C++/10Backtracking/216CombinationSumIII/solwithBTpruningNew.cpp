class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    int sum = 0;
    void backtracking(int k, int n, int start){
        if(path.size()==k){
            if(sum==n){
                ans.push_back(path);
            }
            return;
        }
        for(int i=start;i<=9;i++){
            if(sum>n){
                break;
            }
            // cout<<i<<endl;
            sum+=i;
            path.push_back(i);
            backtracking(k,n,i+1);
            sum-=i;
            path.pop_back();
        }
        // cout<<"new branch:"<<endl;
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1);
        return ans;
    }
};