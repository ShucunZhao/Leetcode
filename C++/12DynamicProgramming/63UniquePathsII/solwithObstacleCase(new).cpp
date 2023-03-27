class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /*
            dp[i][j]: the number of paths to get pos i,j
            dp[0][x] = 1 if obstacle[0][x]==0
            dp[x][0] = 1 if obstacle[x][0]==0
            dp[i][j] = dp[i-1][j]+dp[i][j-1]
        */
        if(obstacleGrid[0][0]==1) return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size(); 
        vector<vector<int> > dp(m, vector<int>(n, 1));
        bool flagRow = 0, flagCol = 0;
        for(int i=0;i<m;i++){
            if(flagRow||obstacleGrid[i][0]==1){
                dp[i][0]=0;
                flagRow = 1;
            } 
        }
        for(int j=0;j<n;j++){
            if(flagCol||obstacleGrid[0][j]==1){
                dp[0][j]=0;
                flagCol = 1;
            } 
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0){
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};