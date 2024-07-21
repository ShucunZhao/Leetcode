#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]=='1') {
                    ans++;
                    dfs(grid, i, j, m, n);
                }
                //if (grid[i][j] == '1') {
                //    bfs(grid, i, j, m, n);
                //    ans++;
                //}
            }
        }
        return ans;
    }

    void dfs(vector<vector<char> >& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i, j-1, m, n);
        dfs(grid, i, j + 1, m, n);
        return;
    }

    void bfs(vector<vector<char> >& grid, int i, int j, int m, int n) {
        queue<vector<int> > Q;
        Q.push({ i,j });
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                vector<int> tmp = Q.front();
                Q.pop();
                int tmpI = tmp[0];
                int tmpJ = tmp[1];
                grid[tmpI][tmpJ] = '0';
                if (tmpI > 0 && grid[tmpI - 1][tmpJ] == '1') Q.push({tmpI-1, tmpJ});
                if (tmpI < m-1 && grid[tmpI + 1][tmpJ] == '1') Q.push({ tmpI + 1, tmpJ });
                if (tmpJ > 0 && grid[tmpI][tmpJ-1] == '1') Q.push({ tmpI, tmpJ-1 });
                if (tmpJ < n - 1 && grid[tmpI][tmpJ+1] == '1') Q.push({ tmpI, tmpJ+1 });
            }
        }
        return;
    }
};

int main(int argc, char* argv[]) {
    //vector<vector<string> > In =
    //{
    //    {"1", "1", "1", "1", "0"},
    //    {"1", "1", "0", "1", "0"},
    //    {"1", "1", "0", "0", "0"},
    //    {"0", "0", "0", "0", "0"}
    //};
    vector<vector<string> > In =
    {
        {"1","1","0","0","0"},
        {"1","1","0","0","0"},
        {"0","0","1","0","0" },
        {"0","0","0","1","1"}
    };
    vector<vector<char> > grid(In.size(), vector<char>(In[0].size()));
    for (int i = 0; i < In.size(); ++i) {
        for (int j = 0; j < In[0].size(); ++j) {
            grid[i][j] = In[i][j][0];
        }
    }
    Solution S;
    cout << "Res: " << S.numIslands(grid) << endl;
}