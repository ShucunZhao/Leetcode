class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
            Only can move either down or right.
            dp[i][j] is the number of paths when move to row i and col j.
            dp[0][j] = 1;
            dp[i][0] = 1;
            for i>0 or j>0:
            dp[i][j] = dp[i-1][j]+dp[i][j-1]
        */
        vector<vector<int> > dp(m, vector<int>(n, 1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};