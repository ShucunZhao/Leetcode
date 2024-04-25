#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
            Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
                    dp:     0 0  0 0  0 0 0  0 0
            Output: 6 [4,-1,2,1] 
            1.dp[i]: the max sum of subarray end with index i.
            2.dp[i] = max(dp[i-1]+nums[i], nums[i])
            3.dp[x] = 0
        */
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1; i < nums.size();++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    int maxSubArray_greedy(vector<int>& nums) {
        /*
            Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
            Output: 6 [4,-1,2,1] 

            Sol with greedy, only add the subarray elements that can make the sum larger,
            so once we meet the sum is negative we abandon it.
        */
        int sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            ans = max(sum, ans);
            if (sum < 0) {
                sum = 0;
                continue;
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> nums;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res1: " << S1.maxSubArray_greedy(nums) << endl;
        cout << "Res2: " << S1.maxSubArray(nums) << endl;
    }
}