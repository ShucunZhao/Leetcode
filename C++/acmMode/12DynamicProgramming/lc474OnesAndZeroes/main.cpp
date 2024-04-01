#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        /*
            Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
            Output: 4
            1.dp[i][j][k]: the max number of chars that we can choose from index 0 to i of strs to fill the 0-knapsack whose size is j and fill the 1-knpasack whose size is k
            2.if(strs[i]['0']>j||strs[i]['1']>k) dp[i][j][k] = dp[i-1][j][k]
              else: dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-strs[i]['0']][k-strs[i]['1']])
            3.Initial: all is 0
        */
        vector<vector<vector<int> > > dp(strs.size()+1, (vector<vector<int> >(m+1, vector<int>(n + 1, 0))));
        for (int i = 1; i <= strs.size(); ++i) {
            int zeros = countElem(true, strs[i-1]);
            int ones = countElem(false, strs[i-1]);
            for (int j = 0; j <=m; ++j) {
                for (int k = 0; k <= n;++k) {
                    if (zeros > j || ones > k) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                    else {
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i-1][j-zeros][k-ones]+1);
                    }
                }
            }
        }
        return dp[strs.size()][m][n];
    }
    int countElem(bool isZero, string& str) {
        int cnt = 0;
        for (char& c : str) {
            if (isZero && c == '0') cnt++;
            if (!isZero && c == '1') cnt++;
        }
        return cnt;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the strs: " << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        cout << "Enter the m: " << endl;
        string M;
        getline(cin, M);
        if (M == "q") break;
        cout << "Enter the n: " << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<string> strs;
        if (!In.empty()) {
            stringstream ss(In);
            string token;
            while (getline(ss, token, ',')) {
                token = token.substr(1, token.size() - 2);
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                token = token.substr(l, r - l + 1);
                strs.push_back(token);
            }
        }
        int m = stoi(M);
        int n = stoi(N);
        cout << "Res: " << S1.findMaxForm(strs,m,n)<<endl;
    }
}