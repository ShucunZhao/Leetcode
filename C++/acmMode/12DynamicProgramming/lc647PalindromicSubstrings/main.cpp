#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        /*
            Input: s = "abc"
            Output: 3
            1.dp[i][j]: if the string start at i and end at j s.substr(i,j-i+1) is a palindrome
            2.if s[i]==s[j]:
                if(j-i<=1){
                    dp[i][j] = true;
                    cnt+=1;
                }
                else if(dp[i+1][j-1]):
                    dp[i][j] = true;
                    cnt+=1;
                else:
                    dp[i][j] = false;
              else:
                    dp[i][j] = false;
            3.dp[x][x]: false
        */
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        int ans = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        ans++;
                        dp[i][j] = true;
                    }
                    else {
                        if (dp[i + 1][j - 1]) {
                            ans++;
                            dp[i][j] = true;
                        }
                        else {
                            dp[i][j] = false;
                        }
                    }
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return ans;
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
        cout << "Res: " << S1.countSubstrings(s) << endl;;
    }
}