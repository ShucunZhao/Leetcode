class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int preDiff = 0;
        int curDiff;
        int ans = 1;
        for(int i=1;i<nums.size();i++){
            curDiff = nums[i]-nums[i-1];
            if((preDiff>=0&&curDiff<0)||(preDiff<=0&&curDiff>0)){
                ans++;
                preDiff = curDiff;
            }
        }
        return ans;
    }
};