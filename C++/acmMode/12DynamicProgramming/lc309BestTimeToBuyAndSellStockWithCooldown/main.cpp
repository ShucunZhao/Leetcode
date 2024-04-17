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
              dp[i][0]: hold the stock
              dp[i][1]: coldown 
              dp[i][2]: keep the unhold the stock state
              dp[i][3]: unhold today
            2.dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i], dp[i-1][2]-prices[i])
              dp[i][1] = dp[i-1][3]
              dp[i][2] = max(dp[i-1][1], dp[i-1][2])
              dp[i][3] = dp[i][0]+prices[i]
            3.dp[0][0] = -prices[0]
              dp[0][1] = 0
              dp[0][2] = 0
              dp[0][3] = 0
        */
        vector<vector<int> > dp(prices.size(), vector<int>(4));
        dp[0][0] = -prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1] - prices[i]), dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][3];
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
            dp[i][3] = dp[i][0] + prices[i];
        }
        int i = dp.size() - 1;
        return max(dp[i][1], max(dp[i][2], dp[i][3]));
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter prices:" << endl;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<int> prices;
        if (!In.empty()) {
            stringstream ss(In);
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