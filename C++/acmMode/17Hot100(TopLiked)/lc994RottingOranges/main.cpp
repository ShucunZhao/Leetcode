#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int ans = 0;
    int orangesRotting(vector<vector<int> > & grid) {
        /*
        *   0: empty; 1: fresh: 2; rotten
            Input: grid = [[2,1,1],
                           [1,1,0],
                           [0,1,1]]
            ------------------------------
                           [[2,1,1],
                            [1,1,1],
                            [0,1,2]]
        */
        queue<pair<int, int> > Q;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    Q.push(make_pair(i, j));
                }
            }
        }
        bfs(grid, Q);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return ans;
    }
    void bfs(vector<vector<int> >& grid, queue<pair<int, int> > & Q) {
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                int row = Q.front().first;
                int col = Q.front().second;
                Q.pop();
                if (row > 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    Q.push(make_pair(row-1, col));
                }
                if (col > 0 && grid[row][col-1] == 1) {
                    grid[row][col - 1] = 2;
                    Q.push(make_pair(row, col-1));
                }
                if (row < grid.size()-1 && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    Q.push(make_pair(row+1, col));
                }
                if (col <grid[0].size()-1 && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    Q.push(make_pair(row, col+1));
                }
            }
            if (Q.empty()) break;
            ans++;
        }
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
        size_t pos;
        vector<vector<int> > grid;
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
        cout << "Res: " << S1.orangesRotting(grid) << endl;
    }
}