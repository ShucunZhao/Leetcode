#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        // write code here
        /*
            1.dp[i]: the number of ways to get step i
            2.dp[i] = dp[i-1]+dp[i-2]+dp[i-3]+...+dp[0]
                    = dp[0]+dp[1]+...+dp[i-1]
              and then:
              dp[i-1]=dp[0]+dp[1]+...+dp[i-2]
                    ===>
                    dp[i] = dp[i-1]+dp[i-1]
                          = 2*dp[i-1]
            3.dp[0] = 0
              dp[1] = 1
              dp[2] = 2
              dp[3] = 4
        */
        vector<int> dp(number + 1);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= number; ++i) {
            dp[i] = 2 * dp[i - 1];
        }
        return dp[number];
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
        cout << "Res: " << S1.jumpFloorII(n) << endl;
    }
}