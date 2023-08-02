class Solution {
public:
    unordered_map<string, int> ms;
    bool predictTheWinner(vector<int>& nums) {
        /*
            nums = [1,5,233,7]
            dp[i][j], we take elemnts from [i, j] in nums that the max score difference we can get.
            Inference:
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);

                  0   1   2   3
              0   1
              1       5   
              2          233 233
              3               7
            Initialization:
                we know should choose from i to j so that the j must >= i,
                and we need to traverse the up-right part of the dp array.
                need: dp[]
        */
        //This dfs return net score difference of player1 and player2.
        // return getScore(0, nums.size()-1, nums)>=0;
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size()));
        for(int i=0;i<nums.size();i++) dp[i][i] = nums[i];
        for(int i = nums.size()-2;i>=0;i--){
            for(int j=i+1;j<nums.size();j++){
                // cout<<"i:"<<i<<",j:"<<j<<endl;
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][nums.size()-1]>=0;
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