#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
        *   We use 0 to mark the first element if this row or col need to set as 0 and 
        *   handle the first row and col at last to prevent duplcate operation.
                0: row, 0: col
            Input: matrix = [[0,1,2,0],
                             [3,4,5,2],
                             [1,3,1,5]]
                             

            Output: [[0,0,0],
                     [0,0,0],
                     [1,0,1]]
        */
        bool firstRow = false, firstCol = false;
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }
        for (int j = 0; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < matrix[0].size(); ++j) matrix[i][j] = 0;
            }
        }
        for (int j = 1; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < matrix.size(); ++i) matrix[i][j] = 0;
            }
        }
        if (firstCol) {
            for (int i = 0; i < matrix.size(); ++i) matrix[i][0] = 0;
        }
        if (firstRow) {
            for (int j = 0; j < matrix[0].size(); ++j) matrix[0][j] = 0;
        }
    }
};

void printMatrix(vector<vector<int> > & matrix) {
    for (vector<int>& rows : matrix) {
        cout << "[";
        for (int& i : rows) {
            cout << i << ",";
        }
        cout << "]" << endl;
    }
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter matrix: " << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(2, In.size() - 4);
        vector<vector<int> > matrix;
        if (!In.empty()) {
            size_t pos;
            while ((pos = In.find("],[")) != string::npos) {
                stringstream ss(In.substr(0, pos));
                string token;
                vector<int> tmp;
                while (getline(ss, token, ',')) {
                    size_t l = token.find_first_not_of(" ");
                    size_t r = token.find_last_not_of(" ");
                    tmp.push_back(stoi(token.substr(l, r - l + 1)));
                }
                matrix.push_back(tmp);
                In = In.substr(pos + 3);
            }
            stringstream ss(In);
            string token;
            vector<int> tmp;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                tmp.push_back(stoi(token.substr(l, r - l + 1)));
            }
            matrix.push_back(tmp);
        }
        S1.setZeroes(matrix);
        cout << "Res: [";
        printMatrix(matrix);
        cout << "]" << endl;
    }
}