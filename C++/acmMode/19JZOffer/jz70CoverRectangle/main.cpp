#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
        /*
            There two ways to construct a 2*n rectangle by 1*2 small-rectangle
            Assume the rect is below:
             ________   size: 2*4
            |        |
            |________|
            So the construct amount of this rect can be represented these two cases:
             ________
            |      | |   
            |______|_|
            case1: amount(2*(4-1)) + 1(use one small)
             ________
            |  |____|
            |__|____|
            case2: amount(2*(4-2)) + 1(use two small)
            In general, this is a dp problem:
            1.dp[n]: the amount of constrct ways when the width is n of the original rectangle
            2.dp[n] = dp[n-1]+dp[n-2]
            3.dp[0] = 0, dp[1] = 1, dp[2] = 2
        */
        if (number <= 2) return number;
        vector<int> dp(number+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= number; ++i) dp[i] = dp[i - 1] + dp[i - 2];
        return dp[number];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the number:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        int n = stoi(N);
        cout << "Res:" << S1.rectCover(n) << endl;
    }
}