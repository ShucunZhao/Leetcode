#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            Input: nums = [1,1,1,1,1], target = 3
            Output: 5
            Explanation:
                -1 + 1 + 1 + 1 + 1 = 3
                +1 - 1 + 1 + 1 + 1 = 3
                +1 + 1 - 1 + 1 + 1 = 3
                +1 + 1 + 1 - 1 + 1 = 3
                +1 + 1 + 1 + 1 - 1 = 3
            Assume: sumA(+), sumB(-), sum
            sumA+sumB = sum
            sumA-sumB = target
            ===>
                2*sumA = sum+target
                Because of sumA, sum, target are integer, so that the condition1: sum+target must be integer

            sumA = (sum+target)/2
            and  0=<sumA<=sum
            ===>  
                   0=<sum+target<=2sum
                 ===>
                     condition2: target<=sum
            Then:
                we need to find all the cases amount that can choose elements from nums to fill the knapscak target
            (01Knapscak problem)
            1.dp[i][j]: the cases amount that choose elements from 0 to i in nums to fill knapsack whose size is j
            2.if nums[i]>j the dp[i][j] should equal to the last case: dp[i-1][j]
              if nums[i]<=j there are two cases:
                case1: unchoose nums[i]: dp[i-1][j]
                case2: choose nums[i]: dp[i-1][j-nums[i]]
                so: dp[i][j] = dp[i-1][j]+dp[i-1][j-nums[i]]
            3.Initial:
                dp[i][0] = 1 because if the size is 0 we can choose nothing to fill which is treated as one case.
                dp[0][j]=dp[0][j]+1 that nums[0] == j 
        */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 == 1) return 0;
        if (abs(target) > sum) return 0;
        int sumA = (sum + target) / 2;
        vector<vector<int> > dp(nums.size(), vector<int>(sumA +1, 0));
        for (int i = 0; i < nums.size(); ++i) {
            dp[i][0] = 1;
        }
        for (int j = 0; j <= sumA; ++j) {
            if (nums[0] == j) {
                dp[0][j]++;
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j <= sumA; ++j) {
                if (nums[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j]+dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[nums.size()-1][sumA];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter nums:"<<endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        cout << "Enter taret:" << endl;
        string T;
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
                token = token.substr(l, r - l + 1);
                nums.push_back(stoi(token));
            }
        }
        int target = stoi(T);
        cout << "Res: " << S1.findTargetSumWays(nums, target) << endl;
    }
}