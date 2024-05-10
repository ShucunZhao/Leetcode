#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int cutRope(int n) {
        /*
           4:  1,3;  2,2
           5:  1,4;  2,3
           1.dp[i]: the max product of cutting i
           2.for(int i=1;i<=n;++i){
                for(int j=1;j<=i/2;++j){
                    max(ans, dp[j]*dp[i-j])
                }
           }
           3.dp[0] = 0;
             dp[1] = 1;
             dp[2] = 2;
             dp[3] = 3
        */
        if (n == 2) return 1;
        if (n == 3) return 2;
        vector<long long> dp(n + 1, 0);
        long long ans = 0;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            for (int j = 1; j <= i / 2; ++j) {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
            ans = max(ans, dp[i]);
        }
        return (int)ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the n:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        int n = stoi(In);
        cout << "Res: " << S1.cutRope(n) << endl;
    }
}