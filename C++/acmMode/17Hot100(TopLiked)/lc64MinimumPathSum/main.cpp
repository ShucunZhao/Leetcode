#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
            grid = [[1,3,1],
                    [1,5,1],
                    [4,2,1]]
            1.dp[i][j]: the minimum sum of position i,j
            2.dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
            3.dp[x][0] = grid[x][0], dp[0][x] = grid[0][x]
        */
        vector<vector<int> > dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i) {
            dp[i][0] = grid[i][0]+dp[i-1][0];
        }
        for (int j = 1; j < grid[0].size(); ++j) {
            dp[0][j] = grid[0][j]+dp[0][j-1];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
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
        if (!In.empty()) {
            size_t pos;
            while ((pos = In.find("],[")) != string::npos) {
                stringstream ss(In.substr(0, pos));
                string token;
                In = In.substr(pos + 3);
                vector<int> tmp;
                while (getline(ss, token, ',')) {
                    size_t l = token.find_first_not_of(" ");
                    size_t r = token.find_last_not_of(" ");
                    tmp.push_back(stoi(token.substr(l, r - l + 1)));
                }
                grid.push_back(tmp);
            }
            stringstream ss(In);
            string token;
            vector<int> tmp;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                tmp.push_back(stoi(token.substr(l, r - l + 1)));
            }
            grid.push_back(tmp);
        }
        cout << "Res: " << S1.minPathSum(grid) << endl;
    }
}