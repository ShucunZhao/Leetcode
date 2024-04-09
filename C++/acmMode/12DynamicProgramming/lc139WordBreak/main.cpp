#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //return wordBreak_nonMem(s, wordDict);
        //unordered_map<string, bool> mem;
        //return wordBreak_Mem(s, wordDict, mem);
        return DP(s, wordDict);
    }
    bool wordBreak_nonMem(string s, vector<string>& wordDict) {
        /*
            Input: s = "leetcode", wordDict = ["leet","code"]
            Output: true
        */
        if (s.empty()) return true;
        for (int i = 0; i < s.size(); ++i) {
            string str = s.substr(0, i + 1);
            if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end()&& wordBreak_nonMem(s.substr(i + 1), wordDict)) {
                return true;
            }
        }
        return false;
    }
    bool wordBreak_Mem(string s, vector<string>& wordDict, unordered_map<string, bool> & mem) {
        /*
            Input: s = "leetcode", wordDict = ["leet","code"]
            Output: true
        */
        if (mem.count(s) > 0) return mem[s];
        if (s.empty()) return true;
        for (int i = 0; i < s.size(); ++i) {
            string str = s.substr(0, i + 1);
            if (find(wordDict.begin(), wordDict.end(), str) != wordDict.end() && wordBreak_Mem(s.substr(i + 1), wordDict,mem)) {
                mem[str] = true;
                return true;
            }
    /*        else { //Cannot do memorize here because it doesn't mean invalid!
                mem[str] = false;
            }*/
        }
        mem[s] = false; // Only we sure that the s cannot be splited we do the memorize 
        return false;
    }
    bool DP(string s, vector<string>& wordDict) {
        /*
            1.dp[i]: if the string s.substr(0, i) can find in wordDict
            2.if dp[j] is true and s.substr(j, i-j+1) can find in  wordDict, dp[i] is also true, else dp[i] is false
            3.dp[0]: true because an empty string "" can find in wordDict
        */
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the s:" << endl;
        string s;
        getline(cin, s);
        if (s == "q") break;
        cout << "Enter the wordDict:" << endl;
        string WD;
        getline(cin, WD);
        if (WD == "q") break;
        WD = WD.substr(1, WD.size() - 2);
        vector<string> wordDict;
        if (!WD.empty()) {
            stringstream ss(WD);
            string token;
            while (getline(ss, token, ',')) {
                size_t l = token.find_first_not_of(" ");
                size_t r = token.find_last_not_of(" ");
                token = token.substr(l, r - l + 1);
                token = token.substr(1, token.size() - 2);
                wordDict.push_back(token);
            }
        }
        s = s.substr(1, s.size() - 2);
        cout << "Res: " << S1.wordBreak(s, wordDict) << endl;
    }
}