#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*
            1.dp[i]: the minumum number of coins to make up the amount i
            2.for(int i=0;i<=amount;++i){
                for(int j = 0;j<coins.size();++i){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
            3.dp[0]=0,dp[i] = 1 if coins[i]==i

            [1,2,5] , 11
            [0,-1...-1]
        */
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i&&dp[i-coins[j]] != -1) {
                    if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {
                        dp[i] = dp[i - coins[j]] + 1;
                    }
                }
            }
        }
        return dp[amount];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string C;
        cout << "Enter coins:" << endl;
        getline(cin, C);
        if (C == "q") break;
        string A;
        cout << "Enter amount:" << endl;
        getline(cin, A);
        if (A == "q") break;
        C = C.substr(1, C.size()-2);
        vector<int> coins;
        if (!C.empty()) {
            stringstream ss(C);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                token = token.substr(l, r - l + 1);
                coins.push_back(stoi(token));
            }
        }
        int amount = stoi(A);
        cout << "Res: " << S1.coinChange(coins, amount) << endl;
    }
}