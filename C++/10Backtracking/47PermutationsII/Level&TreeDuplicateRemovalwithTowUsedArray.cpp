class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(vector<int> & nums, vector<bool> & used1, vector<bool> & used2){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used2[i]){
                continue;
            }
            if(i>0&&nums[i-1]==nums[i]&&!used1[i-1]){
                continue;
            }
            used1[i] = 1;
            used2[i] = 1;
            path.push_back(nums[i]);
            backtracking(nums, used1, used2);
            used1[i] = 0;
            used2[i] = 0;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used1(nums.size());
        vector<bool> used2(nums.size());
        backtracking(nums, used1, used2);
        return ans;
    }
};