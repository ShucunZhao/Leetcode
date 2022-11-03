class Solution {
public:
    vector<int> path;
    vector<vector<int> > ans;
    void backtracking(vector<int>& nums, int start){
        if(start==nums.size()){
            return;
        }
        for(int i= start;i<nums.size();i++){
            if(i>start&&nums[i]==nums[i-1]){//Duplicates removal: If i larger than start means already finished traversal of first showing one of duplicates, 
                                            //then need to skip the duplicates after previous.
                continue;
            }
            path.push_back(nums[i]);
            ans.push_back(path);
            backtracking(nums, i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        ans.push_back({});
        sort(nums.begin(), nums.end());//Need to sort at first to let all duplicates elements on the same side.
        backtracking(nums, 0);
        return ans;
    }
};