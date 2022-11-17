/*
/ This is a full knapsack question, and this question cannot use 2D array to deal with!
 * dp[i]: The number of "permuations" that the previous objects can fill the knapsack target i.
 * Inference formula: if nums[j] <= j: dp[i] += dp[i-nums[i]]
 * Initialization: dp[0] = 1 because if knapsack is 0 you can put empty element {} into it, which as one case.                     
 * Iterator order: This is the key point here, because the question ask to get the number of permutations, then 
                   we need to interatre the size of knapsack first and then the objects. And because it's a full
                   package problem so you need to iterate from front to back.
 * Print dp for debug.
 */
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        //vector<unsigned int> dp(target+1, 0); Use unsigned integer to prevent overflow when the dp value is bigger than INT_MAX.
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(int j=1;j<=nums.size();j++){
                if(nums[j-1]<=i&&(dp[i]<INT_MAX-dp[i-nums[j-1]])){//Prevent overflow.
                    dp[i]+=dp[i-nums[j-1]];
                }
            }
        }
        // for(int i=0;i<=target;i++){
        //     cout<<"dp["<<i<<"]: "<<dp[i]<<endl;
        // }
        return dp[target];
    }
};
//