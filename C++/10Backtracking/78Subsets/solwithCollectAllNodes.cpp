class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(vector<int>& nums, int start){
        if(start==nums.size()){
            return;
        }
        for(int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            ans.push_back(path);
            backtracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back({});
        backtracking(nums, 0);
        return ans;
    }
};