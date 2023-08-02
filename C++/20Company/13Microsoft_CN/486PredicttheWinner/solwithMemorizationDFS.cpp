class Solution {
public:
    unordered_map<string, int> ms;
    bool predictTheWinner(vector<int>& nums) {
        /*
            dp1:   
                    l       r
            nums = [1,5,233,7]
            dp2:
        */
        //This dfs return net score difference of player1 and player2.
        return getScore(0, nums.size()-1, nums)>=0;
    }
    int getScore(int left, int right, vector<int> & nums){
        if(left==right){
            return nums[left];
        }
        string s = to_string(left)+","+to_string(right);
        if(ms.count(s)) return ms[s];
        int score = max(nums[left]-getScore(left+1, right, nums), nums[right]-getScore(left,right-1,nums));
        ms[s] = score;
        return ms[s];
    }
};