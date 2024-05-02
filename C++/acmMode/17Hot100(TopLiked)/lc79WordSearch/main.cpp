#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int m;
    int n;
    int size;
    bool exist(vector<vector<char>>& board, string word) {
        /*
            up,down,left,right
            Because each position can be the starting position, so we
            need a for-loop to traverse.
        */
        m = board.size();
        n = board[0].size();
        size = word.size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                vector<vector<bool> > isVisited(m, vector<bool>(n, false));
                if (dfs(i, j, isVisited, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(int row, int col, vector<vector<bool> >& isVisited, vector<vector<char>>& board, string& word, int start) {
        if (start == size) return true;
        if (row < 0 || row >= m || col < 0 || col >= n || isVisited[row][col]) return false;
        if (board[row][col] != word[start]) return false;
        isVisited[row][col] = true;
        bool up = dfs(row - 1, col, isVisited, board, word, start + 1);
        bool down = dfs(row + 1, col, isVisited, board, word, start + 1);
        bool left = dfs(row, col - 1, isVisited, board, word, start + 1);
        bool right = dfs(row, col + 1, isVisited, board, word, start + 1);
        if (up || down || left || right) return true;
        isVisited[row][col] = false;
        return false;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the board:" << endl;
        string B;
        getline(cin, B);
        if (B == "q") break;
        cout << "Enter the word:" << endl;
        string word;
        getline(cin, word);
        if (word == "q") break;
        B = B.substr(2, B.size() - 4);
        vector<vector<char> > board;
        if (!B.empty()) {
            size_t pos;
            while ((pos = B.find("],[")) != string::npos) {
                string tmp = B.substr(0, pos);
                B = B.substr(pos + 3);
                vector<char> rows;
                tmp = tmp.substr(1, tmp.size() - 2);
                size_t pos2;
                while ((pos2 = tmp.find("\",\"")) != string::npos) {
                    string tmp2 = tmp.substr(0, pos2);
                    tmp = tmp.substr(pos2 + 3);
                    rows.push_back(tmp2[0]);
                }
                rows.push_back(tmp[0]);
                board.push_back(rows);
            }
            vector<char> rows;
            B = B.substr(1, B.size() - 2);
            size_t pos2;
            while ((pos2 = B.find("\",\"")) != string::npos) {
                string tmp2 = B.substr(0, pos2);
                B = B.substr(pos2 + 3);
                rows.push_back(tmp2[0]);
            }
            rows.push_back(B[0]);
            board.push_back(rows);
        }
        word = word.substr(1, word.size() - 2);
        cout << "Res: " << S1.exist(board, word)<<endl;
    }
}