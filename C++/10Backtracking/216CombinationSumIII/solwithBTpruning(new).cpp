class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(int start, int sum, int k, int n){
        if(path.size()==k){
            if(sum==n){
                ans.push_back(path);
            }
            return;
        }
        for(int i=start;i<=9&&sum+i<=n;i++){
            sum+=i;//1,3,6,10,15,21,28,36,45
            path.push_back(i);//[1,2,3,4,5,6,7,8,9]
            backtracking(i+1, sum, k, n);
            sum-=i;//
            path.pop_back();//[1,2,]
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(1, 0, k, n);
        return ans;
    }
};