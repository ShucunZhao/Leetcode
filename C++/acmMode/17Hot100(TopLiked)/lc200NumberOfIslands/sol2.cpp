#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        /*
            grid =
                  ["1","1","1","1","0"],
                  ["1","1","0","1","0"],
                  ["1","1","0","0","0"],
                  ["0","0","0","0","0"]
        */
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col) {
        if (i < 0 || i >= row || j < 0 || j >= col || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j, row, col);
        dfs(grid, i + 1, j, row, col);
        dfs(grid, i, j - 1, row, col);
        dfs(grid, i, j + 1, row, col);
        return;
    }
};

int main(int argc, char* argv[]) {
    vector<vector<string> > In = { {"1","1","0","0","0"},
                                   {"1","1","0","0","0"},
                                   {"0","0","1","0","0" },
                                   {"0","0","0","1","1"} };
    vector<vector<char> > grid(In.size(), vector<char>(In[0].size()));
    for (int i = 0; i < In.size(); ++i) {
        for (int j = 0; j < In[0].size(); ++j) {
            grid[i][j] = In[i][j][0];
        }
    }
    Solution S1;
    cout << "Res: " << S1.numIslands(grid) << endl;
}