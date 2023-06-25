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
            if(used1[i]) continue;
            if(i>0&&nums[i-1]==nums[i]&&!used2[i-1]) continue;
            path.push_back(nums[i]);
            used1[i] = true;
            used2[i] = true;
            backtracking(nums, used1, used2);
            path.pop_back();
            used1[i] = false;
            used2[i] = false;
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