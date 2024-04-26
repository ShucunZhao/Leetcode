#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
                s = "abc", t = "ahbgdc"

                   a h b g d c
                a  1 1 1 1 1 1
                b  1 1 2 2 2 2
                c  1
        */
        if (s == "") return true;
        if (t == "") return false;
        vector<vector<int> > dp(s.size(), vector<int>(t.size()));
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == t[0]) {
                while (i < s.size()) dp[i++][0] = 1;
            }
        }
        for (int j = 0; j < t.size(); j++) {
            if (s[0] == t[j]) {
                while (j < t.size()) dp[0][j++] = 1;
            }
        }
        for (int i = 1; i < s.size(); ++i) {
            for (int j = 1; j < t.size(); ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
            }
        }
        return dp[s.size() - 1][t.size() - 1] == s.size();
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
        cout << "Enter the t:" << endl;
        string t;
        getline(cin, t);
        if (t == "q") break;
        t = t.substr(1, t.size() - 2);
        cout << "Res: " << S1.isSubsequence(s, t) << endl;
    }
}