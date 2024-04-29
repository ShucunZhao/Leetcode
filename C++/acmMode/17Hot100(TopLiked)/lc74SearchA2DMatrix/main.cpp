#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*                   0 
            Input: matrix = [[1,3,5,7],
                              l
                             [10,11,16,20],
                               r  
                             [23,30,34,60]], 
                                        r
                                        11
            target = 3
            l = 0, r = 11
            m = l+(r-l)/2 = 5
            row = m/matrix.size() = 5/3 = 1
            rol = m/matrix[0].size() = 5%4 = 1
            ------------------
            l = 0, r = 4, m = 2
            row = 2/3 = 0, col = 2%4 = 2
        */
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int row = mid / n;
            int col = mid % n;
            if (matrix[row][col] > target) {
                r = mid - 1;
            }
            else if (matrix[row][col]<target) {
                l = mid + 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the matrix: " << endl;
        string M;
        getline(cin, M);
        if (M == "q") break;
        cout << "Enter the target: " << endl;
        string T;
        getline(cin, T);
        if (T == "q") break;
        M = M.substr(2, M.size() - 4);
        vector<vector<int> > matrix;
        if (!M.empty()) {
            size_t pos;
            while ((pos = M.find("],[")) != string::npos) {
                stringstream ss(M.substr(0,pos));
                M = M.substr(pos + 3);
                string token;
                vector<int> tmp;
                while (getline(ss, token, ',')) {
                    size_t l = token.find_first_not_of(" ");
                    size_t r = token.find_last_not_of(" ");
                    tmp.push_back(stoi(token.substr(l, r - l + 1)));
                }
                matrix.push_back(tmp);
            }
            stringstream ss(M);
            string token;
            vector<int> tmp;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                tmp.push_back(stoi(token.substr(l, r - l + 1)));
            }
            matrix.push_back(tmp);
        }
        int target = stoi(T);
        cout << "Res: " << S1.searchMatrix(matrix, target) << endl;
    }
}