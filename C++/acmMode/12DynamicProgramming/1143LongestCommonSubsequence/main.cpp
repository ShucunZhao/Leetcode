#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
            text1 = "abcde", text2 = "ace" 
               a  c  e
            a  1  1  1
            b  1  1  1   
            c  1  2  2
            d  1  2  2
            e  1  2  3
        */
        vector<vector<int> > dp(text1.size(), vector<int>(text2.size()));
        for (int i = 0; i < text1.size(); ++i) {
            if (text1[i] == text2[0]) {
                while(i<text1.size()) dp[i++][0] = 1;
                break;
            }
        }
        for (int j = 0; j < text2.size(); ++j) {
            if (text2[j] == text1[0]) {
                while (j < text2.size()) dp[0][j++] = 1;
                break;
            }
        }
        for (int i = 1; i < text1.size(); ++i) {
            for (int j = 1; j < text2.size(); ++j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.size() - 1][text2.size() - 1];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string T1;
        cout << "Enter text1:" << endl;
        getline(cin, T1);
        if (T1 == "q") break;
        T1 = T1.substr(1, T1.size() - 2);
        string T2;
        cout << "Enter text2:" << endl;
        getline(cin, T2);
        if (T2 == "q") break;
        T2 = T2.substr(1, T2.size() - 2);
        cout << "Res: " << S1.longestCommonSubsequence(T1, T2) << endl;
    }
}