class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(int start, int curSum, int target){
        if(curSum>target){
            return;
        }
        if(curSum==target){
            if(path.size()>1){
                ans.push_back(path);
            }
            return;
        }
        for(int i=start;i<=target;i++){
            if(!path.empty()&&path.back()+1!=i){
                continue;
            }
            curSum+=i;
            path.push_back(i);
            backtracking(i+1, curSum, target);
            path.pop_back();
            curSum-=i;
        }
        return;
    }
    vector<vector<int> > FindContinuousSequence(int sum) {
        backtracking(1, 0, sum);
        return ans;
    }
};