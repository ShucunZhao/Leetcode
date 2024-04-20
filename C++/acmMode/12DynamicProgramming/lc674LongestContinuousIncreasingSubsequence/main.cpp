#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        /*
            Input: nums = [1,3,5,4,7]
            Output: 3
            1.dp[i]: the longest continouous subsequence of nums[0,i]
            2.for i in range(0, nums.size()):
                if(nums[i]>nums[i-1]){
                    dp[i] = dp[i-1]+1
                }
                max(dp[i], ans)
                        
            3.dp[x]: 1
        */
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            ans = max(ans, dp[i]);
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
        cout << "Res: " << S1.findLengthOfLCIS(nums) << endl;
    }
}