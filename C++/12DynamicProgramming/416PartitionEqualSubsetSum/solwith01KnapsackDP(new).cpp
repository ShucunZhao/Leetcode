class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
        dp[i][j]: If can find some objs to fill the knapsack which size is j from 0 to index i to choose objs.
        dp[i][j] = dp[i-1][j]||(nums[i]==j)||dp[i-1][j-nums[i]]
        nums = [1,5,11,5], halfSum = 11
                    packSize: 0 1 2 3 4 5 6 7 8 9 10 11
            Object:    1      0 1 0 0 0 0 0 0 0 0 0  0
                       5      0 
                       11     0
                       5      0
        */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2==1) return 0;
        sum/=2;
        vector<vector<bool> > dp(nums.size(), vector<bool>(sum+1, 0));
        for(int j=0;j<=sum;j++){
            if(nums[0]==j){
                dp[0][j] = 1;
                break;
            }
        }
        for(int i=1;i<nums.size();i++){
            for(int j=1;j<=sum;j++){
                if(dp[i-1][j]){
                    dp[i][j] = 1;
                }
                else{
                    if(nums[i]==j){
                        dp[i][j] = 1;
                    }
                    else if(nums[i]>j){
                        dp[i][j] = 0;                        
                    }
                    else{
                        dp[i][j] = dp[i-1][j-nums[i]];
                    }
                }
            }
        }
        return dp[nums.size()-1][sum];
        //vector<>
    }
};