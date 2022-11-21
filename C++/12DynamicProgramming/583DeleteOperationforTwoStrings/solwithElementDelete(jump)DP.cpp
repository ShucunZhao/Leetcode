/* Solution 1: 
 * Sol is similar to 115, count the delete times of differerent element in two given strings
       at the same time when iterating.
 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        //Initalization
        for(int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=n;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];//When two element is same don't need to delete anyone.
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1] + 2, min(dp[i-1][j]+1, dp[i][j-1]+1));//When two element is different, there three delete cases"
                                                          //I.Only delete word1's one: dp[i][j] = dp[i-1][j] + 1;
                                                          //II.Only delete word2's one: dp[i][j] = dp[i][j-1] + 1;
                                                          //III.Delete both: dp[i][j] = dp[i-1][j-1] + 2;
                                                          //Then dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 2)
                }
            }
        }
        return dp[m][n];
    }
};