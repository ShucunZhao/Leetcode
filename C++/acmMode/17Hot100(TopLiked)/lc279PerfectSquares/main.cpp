#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        /*
            This is a full knapsack question, we can choose the objects infinite to fill a knapsack whose
            size is n, and the object is a perfect square, and the perfect suqare can be calculated by:
            multiply the index itself, like:
            for(int i=0;i*i<n;++i) perfectSquare = i*i;
            1.dp[j]: the least number of objects use to fill the size n knapsack
            2.for(int j=1;j<=n;++j) // size
                dp[j] = j; //Initial the max
                for(int i=1;i*i<=j;++i)
                    dp[j] = min(dp[j],dp[j-i*i]+1)
        */
        vector<int> dp(n + 1);
        for (int j = 1; j <= n; ++j) {
            dp[j] = j;
            for (int i = 1; i * i <= j; ++i) {
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
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
        cout << "Res: " << S1.numSquares(n) << endl;
    }
}