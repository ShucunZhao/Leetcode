#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
            Input: coins = [1,2,5], amount = 11
            Output: 3
            Explanation: 11 = 5 + 5 + 1
            1.dp[i]: the least amount of coins used to fill the amount i
            2.dp[i] = min(dp[i], dp[i-coins[i]]+1)
            for(int i=0;i<=amount;++i){
                if(i>=coins[i]) dp[i] = min(dp[i], dp[i-coins[i]]+1);
            }
            3.dp[0] = 0;
        */
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= amount; ++i) {
            for (int& j : coins) {
                if (i == j) dp[i] = 1;
            }
        }
        for (int i = 0; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0) {
                    if (dp[i - coins[j]] != INT_MAX) dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
    }
};

int main(int argc, char* argv[]) {
    Solution S;
    vector<int> coins = { 1 };
    int amount = 0;
    cout << "Res: " << S.coinChange(coins, amount) << endl;
}