#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            Input: nums = [2,3,2]
            Output: 3
            1.dp[i]: the max money can get in position i and rob the head,
            2.dp[i] = max(dp[i-1], dp[i-2]+nums[i])
            3.initial: 
                case1: count position 0 and don't count last pos:
                    dp[0] = nums[0]
                    dp[1] = nums[1]
                case2: don't count position 0 and count last pos:
                    dp[0] = nums[1]
        */
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp1(nums.size()-1, 0);
        vector<int> dp2(nums.size()-1, 0);
        dp1[0] = nums[0];
        dp1[1] = max(dp1[0], nums[1]);
        dp2[0] = nums[1];
        dp2[1] = max(dp2[0], nums[2]);
        for (int i = 2; i < nums.size() - 1; ++i) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        for (int i = 2; (i+1) < nums.size(); ++i) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i + 1]);
        }
        return max(dp1[nums.size() - 2], dp2[nums.size() - 2]);
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the nums:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        N = N.substr(1, N.size() - 2);
        vector<int> nums;
        if (!N.empty()) {
            stringstream ss(N);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                token = token.substr(l, r - l + 1);
                nums.push_back(stoi(token));
            }
        }
        cout << "Res: " << S1.rob(nums) << endl;
    }
}