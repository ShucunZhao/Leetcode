#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            1.In day i:
              dp[i][0]: the first time to hold a stock
              dp[i][1]: unhold and never sell any stock before
              dp[i][2]: the second time to hold a stock 
              dp[i][3]: unhold(the second time and has hold one before) stock 
            2.dp[i][0] = max(dp[i-1][0],-prices[i]), dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i])
              dp[i][2] = max(dp[i-1][2], dp[i-1][1]-prices[i]),dp[i][3] = max(dp[i-1][3], dp[i-1][2]+prices[i])
              dp[i][4] = 
            3.dp[0][0]=-prices[0], dp[0][1] = 0, dp[0][2] = -prices[0], dp[0][3] = 0
        */
        vector<vector<int> > dp(prices.size(), vector<int>(4));
        dp[0][0] = -prices[0];
        dp[0][2] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][3]);
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the prices:" << endl;
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