#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        /*
            1.dp[i][j]: the max can get in pos i,j
            2.dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
            3.Can assign (m+1)*(n+1) size so that no need to initialize
        */
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the grid:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(2, In.size() - 4);
        vector<vector<int> > grid;
        size_t pos;
        while ((pos = In.find("],[")) != string::npos) {
            string token1 = In.substr(0, pos);
            In = In.substr(pos + 3);
            stringstream ss(token1);
            string token2;
            vector<int> tmp;
            while (getline(ss, token2, ',')) {
                size_t l = token2.find_first_not_of(" ");
                size_t r = token2.find_last_not_of(" ");
                tmp.push_back(stoi(token2.substr(l, r - l + 1)));
            }
            grid.push_back(tmp);
        }
        stringstream ss(In);
        string token2;
        vector<int> tmp;
        while (getline(ss, token2, ',')) {
            size_t l = token2.find_first_not_of(" ");
            size_t r = token2.find_last_not_of(" ");
            tmp.push_back(stoi(token2.substr(l, r - l + 1)));
        }
        grid.push_back(tmp);
        cout << "Res: " << S1.maxValue(grid) << endl;
    }
}