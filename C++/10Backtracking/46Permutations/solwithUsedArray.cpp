class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){//Because this is a permutations question so you need to record the different order
                                      //results, therefore you begin from 0 each time when traversal.
            if(used[i]==1) continue;
            used[i] = 1;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i]=0;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), 0);//Used array: record the used elements for permuation.
        backtracking(nums, used);
        return ans;
    }
};