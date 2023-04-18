class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            Sol: find the longest subsequence and use the word's size to substract it to get the answer.

            dp[i][j]: the longest subsequence in pos i of word2 and j of word1.
            Intialization:
               dp[i][0] = 1 (from i to word2's end when word2[i]==word1[0]) else dp[i][0] = 0;
               dp[0][j] = 1 (from j to word1's end when word1[j]==word2[0]) else dp[0][j] = 0;
            Formula:
                dp[i][j] = max(dp[i-1], dp[j-1]);
                if(word2[i]==word1[j]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }   
                word1: s e a
             word2: e  0 1 1
                    a  0 1 2
                    t  0 1 1 
            ans = word1.size()-dp+word2.size()-dp;
        */
        vector<vector<int> > dp(word2.size()+1, vector<int>(word1.size()+1, 0));
        for(int i=1;i<=word2.size();i++){
            for(int j=1;j<=word1.size();j++){
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                if(word2[i-1]==word1[j-1]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
            }
        }
        return word1.size()+word2.size()-2*dp[word2.size()][word1.size()];
    }
};