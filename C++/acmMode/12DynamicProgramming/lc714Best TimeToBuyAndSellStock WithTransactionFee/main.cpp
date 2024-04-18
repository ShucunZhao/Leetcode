#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        /*
            1.In day i:
                dp[i][0]: hold the stock
                dp[i][1]: unhold the stock
            2.dp[i][0] = max(dp[i-1][0], dp[i-1][1]-prices[i])
              dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]-fee)
            3.dp[0][0] = -prices[0], dp[0][1] = -fee
        */
        vector<vector<int> > dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        //dp[0][1] = -fee;//There are two state when unhold stock, one is sold another is haven't hold any more
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[prices.size() - 1][1]<0?0: dp[prices.size() - 1][1];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter the prices:" << endl;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        string F;
        cout << "Enter the fee:" << endl;
        getline(cin, F);
        if (F == "q") break;
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
        int fee = stoi(F);
        cout << "Res: " << S1.maxProfit(prices,fee)<<endl;
    }
}