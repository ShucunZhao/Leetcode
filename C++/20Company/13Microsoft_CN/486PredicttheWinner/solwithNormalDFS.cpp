class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        /*
            dp1:   
                    l       r
            nums = [1,5,233,7]
            dp2:
        */
        return getScore(0, nums.size()-1, nums)>=0;
    }
    int getScore(int left, int right, vector<int> & nums){
        if(left==right){
            return nums[left];
        }
        return max(nums[left]-getScore(left+1, right, nums), nums[right]-getScore(left,right-1,nums));
    }
};