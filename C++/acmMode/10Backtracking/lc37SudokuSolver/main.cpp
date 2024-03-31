#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        // for (int i = 0; i < row; ++i) {
        for (int i = 0; i < board.size(); ++i) { //We should check the whole row
            if (board[i][col] == c) return false;
        }
        // for (int j = 0; j < col; ++j) {
        for (int j = 0; j < board[0].size(); ++j) {//We should check the whole col
            if (board[row][j] == c) return false;
        }
        /* 
                     0 1 2 3
                   0 . . . .
                   1 . Q . .
                   2 . . . . 
                   3 . . . x(3,3)
        */
        int rowStart = (row / 3) * 3;
        int colStart = (col / 3) * 3;
        for (int i = rowStart; i < rowStart+3; ++i) {
            for (int j = colStart; j < colStart +3; ++j) {
                if (board[i][j] == c) return false;
            }
        }
        return true;
    }
    //bool backtracking(vector<vector<char>>& board, int row, int col) {
      bool backtracking(vector<vector<char>>&board) {//We should traverse whole board each time 
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; ++c) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            bool check = backtracking(board);
                            if (check) return true;
                        }
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string In;
        cout << "Enter the board: " << endl;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        /*
        *       0123456 
                [x,x,x],[x,x,x],[x,x,x]
        */
        vector<vector<char> > board;
        size_t pos;
        while ((pos = In.find("],[")) != string::npos) {
            string tmp(In.begin() + 1, In.begin() + pos);
            stringstream ss(tmp);
            string token;
            vector<char> boardRow;
            while (getline(ss, token, ',')) {
                boardRow.push_back(token[1]);
            }
            board.push_back(boardRow);
            In = In.substr(pos + 2);
        }
        string tmp = In.substr(1, In.size() - 2);
        stringstream ss(tmp);
        string token;
        vector<char> boardRow;
        while (getline(ss, token, ',')) {
            boardRow.push_back(token[1]);
        }
        board.push_back(boardRow);
        S1.solveSudoku(board);
        cout << "Res:" << endl;
        cout << "[";
        for (vector<char>& Row : board) {
            cout << "[";
            for (char & c : Row) {
                cout << c << ",";
            }
            cout << "]";
        }
        cout << "]" << endl;
    }
}