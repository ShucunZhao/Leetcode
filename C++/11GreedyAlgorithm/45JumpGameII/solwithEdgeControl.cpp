class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int ans = 0, curMaxEnd = 0, nextMaxEnd = 0;
        for(int i=0;i<nums.size();i++){
            nextMaxEnd = max(i+nums[i], nextMaxEnd);
            if(i==curMaxEnd){
                if(curMaxEnd<nums.size()-1){
                    ans++;
                    curMaxEnd = nextMaxEnd;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};