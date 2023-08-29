class Solution {
public:
    int maxCoins(vector<int>& nums) {
        /*
            nums = 1 [3,x,5,8] 1
            nums = 1 [3,x,8] 1
            nums = 1 [x,8] 1
            nums = 1 [x] 1
            3*1*5 + 3*5*8 + 1*3*8 + 1*8*1 = 167.

            Sol1 with backtracking to calculate the path of burst order.
            Sol2 with DP to calculate the final coins result:
                This question means we burst ballon from i to j and need to get the max coins.
                Then we define the index k is the last one to be bursted and left is k'left  one
                while right is k'right one, so:
                    maxCoins = dp[i][left] + dp[right][j] + nums[left]*nums[k]*nums[right]
                ~~ dp[i][j] = max(dp[i][j], dp[i][left] + dp[right][j] + nums[left]*nums[k]*nums[right]) where
                    is from i to j.
            
            Traverse order: from inference formula we can know the traverse order should be from back to front 
            because we need to know right which is k+1 to get the current dp.

        nums = [3,1,5,8]
        */
        int size = nums.size();
        if(size==0) return 0;
        vector<vector<int> > dp(size, vector<int>(size, INT_MIN));
        // nums.insert(nums.begin(), 1);
        // nums.push_back(1);
        for(int j=0;j<size;j++){
            for(int i=j;i>=0;i--){
                // dp[i][j] = INT_MIN;
                for(int k=i;k<=j;k++){
                    //left and right value of k.
                    int lV = i==0 ? 1 : nums[i-1];
                    int rV = j==size-1 ? 1 : nums[j+1];
                    // int lV = k==0 ? 1 : nums[k-1];
                    // int rV = k==size-1 ? 1 : nums[k+1];                    
                    //left and right dp sum.
                    int lSum = k==i ? 0 : dp[i][k-1];
                    int rSum = k==j ? 0 : dp[k+1][j];
                    dp[i][j] = max(dp[i][j], lSum+rSum+lV*nums[k]*rV);
                }
            }
        }
        return dp[0][size-1];
    }
};
/*
The reason why in line 35 and 36, the left and right values of k are based on i and j, not k, is because the problem is asking for the maximum coins you can collect by bursting the balloons wisely. This means that you have to consider the optimal order of bursting the balloons, not just the immediate coins you get from bursting one balloon.

The idea behind the dynamic programming solution is to find the maximum coins you can collect by bursting all the balloons from i to j, for every possible subarray of nums. To do this, you have to assume that the last balloon you burst in this subarray is k, and calculate how many coins you get from bursting it, plus how many coins you get from bursting the left and right subarrays that are left after k is gone. The left and right subarrays are [i, k-1] and [k+1, j], respectively.

Now, when you burst balloon k, the coins you get are determined by the left and right values of k, which are the adjacent balloons of k in the original array nums. However, since you have already burst some balloons before k, these adjacent balloons may not be the same as nums[k-1] and nums[k+1]. For example, if nums = [3, 1, 5, 8] and you have already burst balloons 1 and 5, then when you burst balloon 8, its left value is 3 and its right value is 1, not 5 and -1.

Therefore, to find the correct left and right values of k, you have to look at the boundaries of the subarray [i, j], which are i-1 and j+1 in nums. If i-1 or j+1 goes out of bounds of nums, then you treat it as if there is a balloon with a 1 painted on it. This is why in line 35 and 36, you have:

int lV = i==0 ? 1 : nums[i-1]; int rV = j==size-1 ? 1 : nums[j+1];
*/