#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        /*
            Input: n = 4
            Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
        */
        vector<char> elem(n, '.');
        string str(elem.begin(), elem.end());
        vector<string> path(n, str);
        vector<vector<string> > ans;
        int QNums = 0;
        backtracking(path, ans, 0, n, QNums);
        return ans;
    }
    bool isValid(vector<string> & path, int row, int col, int n) {
        for (int i = 0; i < row; ++i) {
            if (path[i][col] == 'Q') return false;
        }
        for (int j = 0; j < col; ++j) {
            if (path[row][j] == 'Q') return false;
        }
        /*
        *        0 1 2 3 4
              0  . . . . . 
              1  . . . . .  
              2  . . Q . .(2,2)
              3  . . . . .
              4  . . . . . 
        */
        for (int i = row - 1, j= col - 1; i >= 0&&j>=0; --i,--j) {
            if (path[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0&&j<n; --i, ++j) {
            if (path[i][j] == 'Q') return false;
        }
        return true;
    }
    void backtracking(vector<string> & path, vector<vector<string> > & ans, int start, int & n, int & QNums) {
        if (start == n) {
            if (QNums == n) {
                ans.push_back(path);
            }
            return;
        }
        //for (int i = start; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isValid(path, start, j, n)) {
                    path[start][j] = 'Q';
                    QNums++;
                    backtracking(path, ans, start + 1, n, QNums);
                    path[start][j] = '.';
                    QNums--;
                }
            }
        //}
    }
};

int main(int argc, char* argv[]) {
	while(true){
        Solution S1;
        cout << "Enter the n:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        int n = stoi(In);
        vector<vector<string> > res = S1.solveNQueens(n);
        cout << "Res: [";
        for (vector<string>& tmp : res) {
            cout << "[";
            for (string& s : tmp) {
                cout << s << ",";
            }
            cout << "]," << endl;
        }
        cout << "]" << endl;
    }
}