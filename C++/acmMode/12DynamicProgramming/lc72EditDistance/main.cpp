#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            Three options:
                Insert a character
                Delete a character
                Replace a character
            Input: word1 = "horse", word2 = "ros"
            Output: 3
            1.dp[i][j]:The min operation amount when word1 ends at pos i-1,
                      word2 ends at pos j-1.
            2.if(word1[i]==word2[j]) dp[i][j] = dp[i-1][j-1](if same char just jump them, do nothing)
              eles:
                opt1 - Insert/Delete:
                    dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1)                    
                opt3 - Replace:(after replace the situation would be "word1[i]==word2[j]")
                    dp[i][j] = dp[i-1][j-1]+1
            3.dp[0][x]=x  q  qq
        */
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        vector<vector<int> > dp(word1.size(), vector<int>(word2.size()));
        if (word1[0] == word2[0]) dp[0][0] = 0;
        else dp[0][0] = 1;
        for (int i = 1; i < word1.size(); i++) {
            dp[i][0] = dp[i - 1][0] + 1;
        }
        for (int j = 1; j < word2.size(); ++j) {
            dp[0][j] = dp[0][j - 1] + 1;
        }
        for (int i = 1; i < word1.size(); ++i) {
            for (int j = 1; j < word2.size(); ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }
        return dp[word1.size() - 1][word2.size() - 1];
    }
    int minDistance2(string word1, string word2) {
        /*
          Update: dp[i][j]: (This is the key point here!!!)The min operation amount when word1 ends at pos i-1,
                      word2 ends at pos j-1.
        */
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        vector<vector<int> > dp(word1.size()+1, vector<int>(word2.size()+1));
        for (int i = 0; i <=word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <=word2.size(); ++j) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter word1: " << endl;
        string word1;
        getline(cin, word1);
        if (word1 == "q") break;
        word1 = word1.substr(1, word1.size()-2);
        cout << "Enter word2: " << endl;
        string word2;
        getline(cin, word2);
        if (word2 == "q") break;
        word2 = word2.substr(1, word2.size() - 2);
        cout << "Res: " << S1.minDistance(word1, word2) << endl;
        cout << "Res2: " << S1.minDistance2(word1, word2) << endl;
    }
}