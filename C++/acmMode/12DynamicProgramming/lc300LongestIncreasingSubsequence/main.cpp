#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
            Input: nums = [10,9,2,5,3,7,101,18]
            Output: 4 ([2,3,7,101])

            1.In pos i:
              dp[i]: the longest subsequence from position 0 to i of nums[0,i]
            2.for(i in nums.size):
                for(j in i):
                    if(nums[i]>nums[j]):
                        find the dp[j]+1
                        and record the max to dp[i].
            3.dp[x]=1,because itself is a subsequence whose length is 1.
        */
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string N;
        cout << "Enter the nums:" << endl;
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
                nums.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.lengthOfLIS(nums) << endl;
    }
}