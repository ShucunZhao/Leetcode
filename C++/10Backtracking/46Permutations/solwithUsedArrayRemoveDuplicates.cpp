class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(vector<int> & nums, vector<bool> & used){
        /*
            nums = [1,2,3]
        */
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return ans;
    }
};