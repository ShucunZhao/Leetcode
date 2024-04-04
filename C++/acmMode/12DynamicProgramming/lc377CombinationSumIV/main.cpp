#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        /*
            This is a upgraded version problem of climbing stair
            dp[i]: the number of schemes to get the stair target i when choose step from the first x elements in nums
            dp[i] = dp[i-nums[x]]
        */
        vector<long> dp(target + 1, 0);
        dp[0] = 1;//Get the stair 0 don't need any step
        for (long i = 0; i <= target; ++i) {
            for (long x = 0; x < nums.size(); ++x) {
                if (i >= nums[x]) {
                    dp[i] += dp[i - nums[x]];
                }
            }
        }
        return dp[target];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter the nunms:" << endl;
        getline(cin, In);
        if (In == "q") break;
        string T;
        cout << "Enter the target:" << endl;
        getline(cin, T);
        if (T == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> nums;
        if (!In.empty()) {
            string token;
            stringstream ss(In);
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        int target = stoi(T);
        cout << "Res: " << S1.combinationSum4(nums, target)<<endl;
    }
}