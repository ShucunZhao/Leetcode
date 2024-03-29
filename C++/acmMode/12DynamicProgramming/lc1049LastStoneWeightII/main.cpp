#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*
            Input: stones = [2,7,4,1,8,1]
            1.Sum: 23
            2.Divide it into two groups:
                groupOne: 23/2 = 11, groupTwo: 23-11 = 12
                (half-)               (half+)
            3.And we need to fill the smaller one knapsack(half-) as much as possible
            4.Then we can find the last ans by: ans = sum -  2*(real size to fill half-)
            So its a 01 knapsack problem.
        */
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int smaller = sum / 2;
        int larger = sum - smaller;
        // sort(stones.begin(), stones.end());
        vector<vector<int> > dp(stones.size(), vector<int>(smaller + 1, 0));
        for (int j = 0; j <= smaller; ++j) {
            if (stones[0] <= j) {
                dp[0][j] = stones[0];
            }
        }
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = 1; j <= smaller; ++j) {
                if(stones[i]>j){
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i-1][j-stones[i]]+stones[i]);
                }
            }
        }
        return sum - 2*dp[stones.size() - 1][smaller];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the stones: " << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> nums;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while(getline(ss, token, ',')){
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                token = token.substr(l, r - l + 1);
                nums.push_back(stoi(token));
            }
        }
        cout << "Res: " << S1.lastStoneWeightII(nums) << endl;
    }
}