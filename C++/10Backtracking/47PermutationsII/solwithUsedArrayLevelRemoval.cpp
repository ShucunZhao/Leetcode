class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    // void backtracking(vector<int>& nums, vector<bool>& used1, vector<bool>& used2){//It can use a same used array to do 
                                                                                    //the level-grade duplicates removal.
    void backtracking(vector<int>& nums, vector<bool>& used1){
        if(path.size()==nums.size()){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used1[i]==1) continue;//Same used array for permuation.
            if(i>0&&nums[i]==nums[i-1]&&used1[i-1]==0) continue;
            // if(i>0&&nums[i]==nums[i-1]&&used2[i-1]==0) continue;
            used1[i] = 1;
            // used2[i] = 1;
            path.push_back(nums[i]);
            backtracking(nums, used1);      
            // backtracking(nums, used1, used2);
            path.pop_back();
            used1[i] = 0;
            // used2[i] = 0;
        }
        return;
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used1(nums.size(), 0);
        // vector<bool> used2(nums.size(), 0);
        sort(nums.begin(), nums.end());
        backtracking(nums, used1); 
        // backtracking(nums, used1, used2);
        return ans;
    }
};