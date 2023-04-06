class Solution {
public:
    unordered_map<int, int> ms;//key: the target, value: the number of combinations to construct target.
    int dfs(vector<int>& nums, int remains){
        if(remains==0){
            return 1;//We do noting can construct the situation where remain size is 0, which is treated as one case.
        }
        if(ms.count(remains)){
            return ms[remains];
        }
        /*
            nums = [1,2,3], target = 4
        */
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(remains>=nums[i]){
                cnt+=dfs(nums, remains-nums[i]);
            }
        }
        ms[remains] = cnt;
        return cnt;
    } 
    int combinationSum4(vector<int>& nums, int target) {
        /*
            Sol with memorization dfs(backtracking).
            nums = [1,2,3], target = 4

        */
        return dfs(nums, target);
    }
};