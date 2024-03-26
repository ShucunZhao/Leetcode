#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        /*
            We can know we divide the whole integer by half and get the max product each time.
            1: 1
            2: 1*1 = 1
            3: 1*2 = 2
            4: 2*2 = 4
            5: 2*3 = 6
            1.dp[i]: the max product we can we in the integer n is i.
            2.dp[5] = max(dp[1]*dp[4], dp[2]*dp[3])
            3.dp[1]=1, dp[2] = 2, dp[3]=3
        */
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            // int ans = INT_MIN;
            for (int j = 1; j <= i / 2; ++j) {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
            // dp[i] = ans;
        }
        return dp[n];
    }
    int integerBreak_sol2(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        return dfs(n);
    }
    int dfs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 3;
        int ans = 0;
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                ans = max(ans, dfs(j) * dfs(i - j));
            }
        }
        return ans;
    }
};

int main(int argc, char* args[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter n:" << endl;
        getline(cin, In);
        if (In == "q") break;
        //In = In.substr(1, In.size() - 2);
        int n = stoi(In);
        cout << "Res1: " << S1.integerBreak(n) << endl;
        cout << "Res2: " << S1.integerBreak_sol2(n) << endl;;
    }
}