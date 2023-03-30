class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            sumA(+) - sumB(-) = sum;
            sumA(+) + sumB(-) = target;
            2*sumA(+) = sum+target;(Case1: because the nums is int array so 2*sumA(+) must be int 
                                    so that sum+target must be even.)
            sumA(+) = (sum+target)/2; 
            And    0<= sumA(+) <=sum;
            --->   0<=(sum+target)/2<=sum;
            --->   0<=sum+target<=2sum
            --->  sum>=-target,   sum>=target(This is case2.)
            so we need to find if put some "+" in given nums can find some weight of objs to fill the 
            knapsack exactly(01 knapsack question.)
            dp[i][j]: the paths to choose objs from 0 to i to fill knapsack whose size is j.
            dp[i][j] = dp[i-1][j]

            nums = [1,1,1,1,1], target = 3;
            bag: 4;

               size:  0 1 2 3 4 
            obj:  1   1 1 0 0 0
                  1   1 0 0 0 0
                  1   1 0 0 0 0
                  1   1 0 0 0 0
                  1   1 0 
        */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target)>sum) return 0;//case2.
        int bag = sum+target;
        if(bag%2==1) return 0;//case1.
        bag/=2;
        bag = abs(bag);
        vector<vector<int> > dp(nums.size(), vector<int>(bag+1, 0));
        for(int j=0;j<=bag;j++){
            if(j==nums[0]) dp[0][j] = 1;
        }
        for(int i=0;i<nums.size();i++){
            dp[i][0] = 1;
        }
        if(nums[0]==0){
            dp[0][0] = 2;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=bag;j++){
                if(nums[i]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[nums.size()-1][bag];
    }
};