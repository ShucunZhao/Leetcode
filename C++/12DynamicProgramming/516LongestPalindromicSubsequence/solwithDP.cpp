/*
 * dp[i][j]: the longest length of subsequence which index is from i to j of source string.
 * Infer formula: For i!j&&j>i: if s[i]==s[j]: dp[i][j] = dp[i+1][j-1]+2
                                else has two cases: I.get head one: dp[i][j] = dp[i+1][j]
                                                   II.get tail one: dp[i][j] = dp[i][j-1]
 * Initialization: when i is equal to j it's a palindrom whose length is 1, so that we need to initial dp[x][x] to 1.
 * Iterate order: Because dp[i][j] is infered by dp[i+1][j-1] so we need to iterate from bottom to top and left to right.
 * Print dp.
 */
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int> > dp(s.size(), vector<int>(s.size(), 0));
        for(int i=0;i<s.size();i++) dp[i][i] = 1;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                if(i<j){
                   if(s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                    else{
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        return dp[0][s.size()-1];
    }
};
