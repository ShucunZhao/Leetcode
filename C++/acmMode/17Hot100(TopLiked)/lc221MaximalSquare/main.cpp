#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*
            matrix = [["1","0","1","0","0"],
                      ["1","0","1","1","1"],
                      ["1","1","1","1","1"],
                      ["1","0","0","1","0"]]

            dp:      [0["1","0","1","0","0"],
                      0["2","0","2","1","1"],
                      0["3","1","3","2","2"],
                      0["4","0","0","3","0"]]
                        0   1   2   3   4
                  
            st: [ 
            curH: 3 
            curW: 1
            ans: 3
        */
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; ++j) dp[0][j] = matrix[0][j]-'0';
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i - 1][j] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            stack<int> st;
            dp[i].insert(dp[i].begin(), -1);
            dp[i].push_back(-1);
            st.push(0);
            for (int j = 1; j < dp[i].size(); ++j) {
                if (dp[i][j] >= dp[i][st.top()]) {
                    st.push(j);
                }
                else {
                    while (dp[i][j] < dp[i][st.top()]) {
                        int curH = dp[i][st.top()];
                        st.pop();
                        int curW = j - st.top()-1;
                        if (curW>=curH) ans = max(ans, curH * curH);
                    }
                    st.push(j);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char * argv[]) {
    vector<vector<string> > matrix = { {"1","0","1","0"},
                                       {"1","0","1","1"},
                                       {"1","0","1","1"},
                                       {"1","1","1","1"} };
    //vector<vector<string> > matrix = { {"0"} };
    vector<vector<char> > charMat(matrix.size(), vector<char>(matrix[0].size()));
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            charMat[i][j] = matrix[i][j][0];
        }
    }
    Solution S1;
    cout << "Res: " << S1.maximalSquare(charMat) << endl;
}