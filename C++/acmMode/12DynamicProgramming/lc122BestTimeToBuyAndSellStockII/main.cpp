#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* Can buy/sell at any time but only holding one stock
            1.dp[i][0]: the max can get if hold stock in day i, dp[i][1]: unhold
            2.dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i]), dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i])
            3.dp[0][0] = -prices[0], dp[0][1] = 0
        */
        vector<vector<int> > dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter prices:" << endl;
        string P;
        getline(cin, P);
        if (P == "q") break;
        P = P.substr(1, P.size() - 2);
        vector<int> prices;
        if (!P.empty()) {
            stringstream ss(P);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                prices.push_back(stoi(token.substr(l, r - l + 1)));
            }
        }
        cout << "Res: " << S1.maxProfit(prices) << endl;
    }
}