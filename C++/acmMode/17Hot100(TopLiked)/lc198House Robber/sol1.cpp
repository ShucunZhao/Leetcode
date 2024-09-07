#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            Input: nums = [1,2,3,1]
            Output: 4
            Constrains:  Two adjacent houses can not be broken into on the same night
            1.dp[i][0]: Do not rob in house[i]
            2.dp[i][1]: Rob in house[i]
            3.dp[i][0] = max(dp[i-1][1], dp[i-1][0]+nums[i])
            4.dp[i][1] = max(dp[i-1][0]+nums[i], dp[i-1][1])
            5.dp[0][0]: 0
            6.dp[0][1]: nums[0]
            for(int i=1;i<nums.size();++i){
                dp[i][0] = max(dp[i-1][1], dp[i-1][0]+nums[i])
                dp[i][1] = max(dp[i-1][0]+nums[i], dp[i-1][1])
            }
            return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
        */
        vector<vector<int> > dp(nums.size(), vector<int>(2, 0));
        dp[0][1] = nums[0];//1
        for (int i = 1; i < nums.size(); ++i) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);//2
            dp[i][1] = dp[i - 1][0] + nums[i];//
        }
        return max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }
};

int main(int argc, char* argv[]) {
    vector<int> nums = { 2,7,9,3,1 };
    Solution S1;
    cout << "Res: " << S1.rob(nums) << endl;
}