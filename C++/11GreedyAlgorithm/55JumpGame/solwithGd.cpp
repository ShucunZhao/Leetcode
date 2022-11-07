class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1){
            return 1;
        }
        int range = 0;
        for(int i = 0;i<=range;i++){
            range = max(i+nums[i], range);
            if(range>=nums.size()-1) return 1;
        }
        return 0;
    }
};