#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*  amount = 5, coins = [1,2,5]
                 0 1 2 3 4 5 
            1(1) 1 1 1 1 1 1
            2(2) 1
            3(5) 1
        */
        vector<vector<int> > dp(coins.size(), vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size(); ++i) dp[i][0] = 1;
        for (int j = 0; j <= amount; ++j) {
            if (coins[0] <= j && j % coins[0] == 0) dp[0][j] = 1;
        }
        for (int i = 1; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (coins[i] > j) {
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                }
            }
        }
        return dp[coins.size() - 1][amount];
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
        cout << "Enter amoint:" << endl;
        getline(cin, A);
        if (A == "q") break;
        C = C.substr(1, C.size() - 2);
        vector<int> coins;
        if (!C.empty()) {
            stringstream ss(C);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                coins.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        int amount = stoi(A);
        cout << "Res: " << S1.change(amount, coins)<<endl;
    }
}