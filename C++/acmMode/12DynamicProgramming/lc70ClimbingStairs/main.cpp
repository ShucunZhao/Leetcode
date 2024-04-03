#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        /*
            1.dp[i]: use the first i elements to fill knapsack whose size is n
        */
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the n:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        int n = stoi(N);
        cout << "Res:" << S1.climbStairs(n)<<endl;
    }
}