#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        /*
            matrix = [["1","0","1","0","0"],
                      ["1","0","1","1","1"],
                      ["1","1","1","1","1"],
                      ["1","0","0","1","0"]]
                      -----------------------
            dp:       [[1,0,1,0,0],
                       [2,0,2,1,1],
                       [3,1,3,2,2],
                       [4,0,0,3,0]]
                       cur: 3
                       st1: 2,
                       st2: 4    
        */
        int ans = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) dp[0][j] = matrix[0][j] - '0';
        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < m; ++i) {
                if (matrix[i][j] != '0') {
                    dp[i][j] = (matrix[i][j] - '0')+dp[i-1][j];
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] != 0) {
                    int curH = dp[i][j];
                    //Monotonic stack for calculate width, store index, find the first smaller index of left-most and right-most
                    stack<int> stL;
                    stack<int> stR;
                    stL.push(j);
                    stR.push(j);
                    for (int l = j-1; l >= 0; --l) {
                        if (dp[i][l] >= curH) {
                            stL.push(l);
                        }
                        else {
                            break;
                        }
                    }
                    for (int r = j+1; r < n; ++r) {
                        if (dp[i][r] >= curH) {
                            stR.push(r);
                        }
                        else {
                            break;
                        }
                    }
                    int curW = (stR.top() - stL.top()) + 1;
                    ans = max(ans, curH * curW);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char * argv[]){
    while (true) {
        Solution S1;
        cout << "Enter the matrix: " << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(2, In.size() - 4);
        vector<vector<char> > matrix;
        size_t pos;
        while ((pos = In.find("],[")) != string::npos) {
            string token1 = In.substr(0, pos);
            In = In.substr(pos + 3);
            size_t pos2;
            vector<char> tmp;
            while ((pos2 = token1.find(",")) != string::npos) {
                string token2 = token1.substr(0, pos2);
                token1 = token1.substr(pos2 + 1);
                tmp.push_back(token2[1]);
            }
            tmp.push_back(token1[1]);
            matrix.push_back(tmp);
        }
        size_t pos2;
        vector<char> tmp;
        while ((pos2 = In.find(",")) != string::npos) {
            string token2 = In.substr(0, pos2);
            In = In.substr(pos2 + 1);
            tmp.push_back(token2[1]);
        }
        tmp.push_back(In[1]);
        matrix.push_back(tmp);
        cout << "Res: " << S1.maximalRectangle(matrix) << endl;
    }
}
