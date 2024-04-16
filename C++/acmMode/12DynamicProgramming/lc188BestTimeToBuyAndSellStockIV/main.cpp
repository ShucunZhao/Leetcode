#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        /* 
            1.In i day:
              dp[i][0]: the first time hold a stock(never buy in before)
              dp[i][1]: the first time unhold a stock(never sell out befor)
              dp[i][2]: the second time hold
              dp[i][3]: the second time unhold
              dp[i][even]: the (even-1) time hold
              dp[i][odd]: the (odd-1) time unhold
              ...
              dp[i][2k]
            2.dp[i][0] = max(dp[i-1][0], -prices[i]);
              dp[i][1] = max(dp[i-1][1], dp[i-1][1-1] + prices[i])
              dp[i][2] = max(dp[i-1][2], dp[i-1][2-1]-prices[i])
              ...
              dp[i][odd] = max(dp[i-1][odd], dp[i-1][odd-1]+prices[i])
              dp[i][even] = max(dp[i-1][even], dp[i-1][even-1]-prices[i])
              ...
              dp[i][2k]
            3.dp[0][j] = -prices[0]
        */
        vector<vector<int> > dp(prices.size(), vector<int>(2*k));
        for(int j=0;j<2*k;j+=2){
            dp[0][j] = -prices[0];
        }
        int ans = INT_MIN;
        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            for (int j = 1; j < 2*k; ++j) {
                if (j % 2 == 1) {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
                    ans = max(ans, dp[i][j]);
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string K;
        cout << "Enter the k:" << endl;
        getline(cin, K);
        if (K == "q") break;
        string In;
        cout << "Enter the prices:" << endl;
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
        int k = stoi(K);
        cout << "Res: " << S1.maxProfit(k, prices) << endl;
    }
}