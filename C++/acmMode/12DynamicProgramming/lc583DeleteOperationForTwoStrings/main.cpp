#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            Input: word1 = "leetcode", word2 = "etco"
            Output: 4
            Convert the problem to find the longest public subsequence, and cout the cutting amount
               e t c o
            l  0 0 0 0
            e  1 1 1 1
            e  1 1 1 1
            t  1 2 2 2
            c  1 2 3 3
            o  1 2 3 4
            d  1 2 3 4
            e  1 2 3 4
            The longest public subsequce is 3, so the cut amount of word2 = word2.size()-4 = 0,
            the cut amount of word1 = word1.size()-4 = 4, total = 0+4=4
        */
        vector<vector<int> > dp(word1.size(), vector<int>(word2.size()));
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] == word2[0]) {
                while (i < word1.size()) dp[i++][0] = 1;
            }
        }
        for (int j = 0; j < word2.size(); ++j) {
            if (word2[j] == word1[0]) {
                while (j < word2.size()) dp[0][j++] = 1;
            }
        }
        for (int i = 1; i < word1.size(); ++i) {
            for (int j = 1; j < word2.size(); ++j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i -1][j -1]+1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return word1.size() + word2.size() - 2 * dp[word1.size() - 1][word2.size() - 1];
    }
};

int main(int argc, char* argv) {
    while (true) {
        Solution S1;
        cout << "Enter the word1:" << endl;
        string W1;
        getline(cin, W1);
        if (W1 == "q") break;
        cout << "Enter the word2:" << endl;
        string W2;
        getline(cin, W2);
        if (W2 == "q") break;
        W1 = W1.substr(1, W1.size() - 2);
        W2 = W2.substr(1, W2.size() - 2);
        cout << "Res: " << S1.minDistance(W1, W2) << endl;
    }
}