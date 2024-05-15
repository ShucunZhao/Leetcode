#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands2(vector<vector<char>>& grid) {
        /*
            sol with bfs and change the 1 to 0
        */
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        queue<pair<int, int> > Q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    ans++;
                    Q.push(make_pair(i, j));
                    while (!Q.empty()) {
                        int size = Q.size();
                        while (size--) {
                            int curRow = Q.front().first;
                            int curCol = Q.front().second;
                            grid[curRow][curCol] = '0';
                            Q.pop();
                            if (curRow - 1 >= 0&&grid[curRow-1][curCol]=='1') {
                                Q.push(make_pair(curRow - 1, curCol));
                            }
                            if (curRow+1 <m && grid[curRow + 1][curCol] == '1') {
                                Q.push(make_pair(curRow + 1, curCol));
                            }
                            if (curCol - 1 >= 0 && grid[curRow][curCol-1] == '1') {
                                Q.push(make_pair(curRow, curCol-1));
                            }
                            if (curCol + 1 < n && grid[curRow][curCol+1] == '1') {
                                Q.push(make_pair(curRow, curCol+1));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
    int numIslands(vector<vector<char>>& grid) {
        /*
            sol with dfs and change the 1 to 0

            [["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]
            [["1","1","0","0","0"],["1","1","0","0","0"],["0","0","1","0","0"],["0","0","0","1","1"]]
        */
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<bool> > isVisited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    dfs(i, j, m, n, grid, isVisited);
                    ans++;
                }
            }
        }
        return ans;
    }
    void dfs(int row, int col, int m, int n, vector<vector<char> >& grid, vector<vector<bool> > & isVisited) {
        if (row < 0 || row >= m || col < 0 || col >= n || isVisited[row][col]||grid[row][col]=='0') {
            return;
        }
        grid[row][col] = '0';
        isVisited[row][col] = true;
        dfs(row - 1, col, m, n, grid, isVisited);
        dfs(row + 1, col, m, n, grid, isVisited);
        dfs(row, col - 1, m, n, grid, isVisited);
        dfs(row, col + 1, m, n, grid, isVisited);
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the grid: " << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(2, In.size() - 4);
        /*
            "1","1","1","1","0"],
            ["1","1","0","1","0"],
            ["1","1","0","0","0"],
            ["0","0","0","0","0"
        */
        vector<vector<char> > grid;
        if (!In.empty()) {
            size_t pos;
            while ((pos = In.find("],[")) != string::npos) {
                string token = In.substr(0, pos);
                token = token.substr(1, token.size() - 2);
                In = In.substr(pos + 3);
                size_t pos2;
                vector<char> tmp;
                while ((pos2 = token.find("\",\"")) != string::npos) {
                    string str = token.substr(0, pos2);
                    token = token.substr(pos2 + 3);
                    tmp.push_back(str[0]);
                }
                tmp.push_back(token[0]);
                grid.push_back(tmp);
            }
        }
        In = In.substr(1, In.size() - 2);
        size_t pos2;
        vector<char> tmp;
        while ((pos2 = In.find("\",\"")) != string::npos) {
            string str = In.substr(0, pos2);
            In = In.substr(pos2 + 3);
            tmp.push_back(str[0]);
        }
        tmp.push_back(In[0]);
        grid.push_back(tmp);
        vector<vector<char> > grid2(grid.begin(), grid.end());
        cout << "Res: " << S1.numIslands(grid) << endl;
        cout << "Res2: " << S1.numIslands2(grid2) << endl;
    }
}