#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        /*
            Input: nums = [1,5,11,5]
            Output: true
            [1, 5, 5] and [11].
            sum: 22
            Find if we can get sum is 11 of elements from the nums.

                  0 1 2 3 4 5 6 7 8 9
            0[3]  f f f t f f f f f f
            1[3]  f f f t f f f f f f 
            2[3]  f f f t f f f f f 
            3[4]  f 
            4[5]  f
            ------------------------
            1.dp[i][j]: if can choose from object 0 to object i to fullfill the size j(true or false)
            2.if nums[i]== j: dp[i][j] = true else: dp[i][j] = dp[i-1][j]
            3.dp[x][0] = false, dp[0][x] = true if nums[0]==x else = false
        */
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1) return false;
        sum /= 2;
        vector<vector<int> > dp(nums.size(), vector<int>(sum+1, false));
        for (int j = 0; j <= sum; ++j) {
            if (nums[0] == j) {
                dp[0][j] = true;
                break;
            }
        }
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (dp[i - 1][j]) dp[i][j] = true;
                else {
                    if (nums[i] > j) dp[i][j] = false;
                    else {
                        dp[i][j] = dp[i - 1][j - nums[i]];
                    }
                } 
            }
        }
        return dp[nums.size() - 1][sum];
    }
};

int main(int argc, char* args[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter the nums:" << endl;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> nums;
        string token;
        stringstream ss(In);
        while (getline(ss, token, ',')) {
            size_t l = token.find_first_not_of(" ");
            size_t r = token.find_last_not_of(" ");
            nums.push_back(stoi(token.substr(l, r - l + 1)));
        }
        cout << "Res: " << S1.canPartition(nums) << endl;
    }   
}