/* dp[i][j]: The mimimum operations number when word1 end with index i, word2 end with index j.
 * Infer formula: If word1[i-1] == word[j-1]: Don't need to add any operation, then dp[i][j] just keep the same as previous state:
                     then: dp[i][j] = dp[i-1][j-1]
                  else word1[i-1]!=word2[j-1]: Three cases:
                      I.Add one operation when delete: I.delete word1: dp[i][j] = dp[i-1][j] + 1;
                                                      II.delete word2: dp[i][j] = dp[i][j-1] + 1;
                     II.Add one operation when add (Same to delete):   I.add word1: dp[i][j] = dp[i][j-1] + 1;
                                                                      II.add word2: dp[i][j] = dp[i-1][j] + 1;
                    III.Add one operation when replace: dp[i][j] = dp[i-1][j-1] + 1;
                 Therefor, dp[i][j] = min(dp[i-1][j],dp[i][j-1],dp[i-1][j])+1;
 * Initialization: From infer formula we can know all dp[i][j] is infered by previous, then we need to initial:
                   dp[0 or not][0] = i: need word1 to do i operations to get empty.
                   dp[0][0 or not] = j: need word2 to do j operations to get empty.
 * Iterate order: From front to back.
 * Print dp array to debug.
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for(int i=0;i<=m;i++) dp[i][0] = i;
        for(int j=0;j<=n;j++) dp[0][j] = j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) +1;
                }
            }
        }
        return dp[m][n];
    }
};