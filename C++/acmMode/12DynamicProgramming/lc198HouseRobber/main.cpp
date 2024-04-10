#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            Input: nums = [1,2,3,1]
            Output: 4
            1.dp[i]: the maximum moneny can get in house i
            2.We can rob in dp[i-1] but do not rob in dp[i] 
                or we can rob in dp[i-2] and dp[i] but do not rob in dp[i-1]
            3.dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
        */
        if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter nums:" << endl;
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
        cout << "Res: " << S1.rob(nums) << endl;
    }
}