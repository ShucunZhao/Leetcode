#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        /*
           "  b a b a d"
              0 1 2 3 4
            0 1 
            1   1
            2     1
            3       1
            4         1
            1.dp[i][j]: if the substring s[i,j] is palindrome(i<j which means the left-down part of the table above)
            2.need to traverse j from 1 to s.size()-2, and the i should traverse from 0 to i
              for(int j=1;j<s.size()-1;++j){
                for(int i=0;i<j;++i){
                    if(s[i]==s[j]){
                        //There two cases:
                        //Case1: aa,aba,
                        if(j-i+1<=3) dp[i][j] = ture;
                        //Case2:
                        else dp[i][j] = dp[i+1][j-1];
                    }
                    else{
                        dp[i][j] = false;
                    }
                 }
              }
              3.dp[i][i] = true from 0 to s.size()-1
        */
        if (s.size() == 1) return s;
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        int maxLen = 0;
        string ans;
        for (int i = 0; i < s.size(); ++i) dp[i][i] = true;
        for (int j = 1; j < s.size(); ++j) {
            for (int i = 0; i < j; ++i) {
                if (s[i] == s[j]) {
                    if (j - i + 1 <= 3) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                else dp[i][j] = false;
                if (dp[i][j]) {
                    if (j - i + 1 > maxLen) {
                        ans = s.substr(i, j-i+1);
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        if (maxLen == 0) return s.substr(0,1);
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter s:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        cout << "Res: " << S1.longestPalindrome(In) << endl;
    }
}