#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
            Input: s = "bbbab"
            Output: 4
            int ans = 0;
            int cnt = 0;
            1.dp[i][j]: the longest palindrome subsequence when the string start at pos i and end at pos j
            2.if (s[i] == s[j]) {
                  if (j - i == 0) {
                      dp[i][j] = 1;
                  }
                  else if (j - 1 == 1) {
                      dp[i][j] = 2;
                  }
                  else {
                      dp[i][j] = dp[i + 1][j - 1] + 2;
                  }
              }
              else {
                  dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
              }
            3.dp[x][x] = 0;
        */
        vector<vector<int> > dp(s.size(), vector<int>(s.size(),0));
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j - i == 0) {
                        dp[i][j] = 1;
                    }
                    else if (j - i == 1) {
                        dp[i][j] = 2;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the s:" << endl;
        string s;
        getline(cin, s);
        if (s == "q") break;
        s = s.substr(1, s.size() - 2);
        cout<<"Res: "<< S1.longestPalindromeSubseq(s) << endl;
    }
}