class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
            dp[i][j]: the min sum of path in position (i,j).
            Because only can move down or right so:
            Infer formula:
            dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            Initialization:
    
            grid =  [1,3,1]
                    [1,5,1]
                    [4,2,1]

            dp:     [1,4,5]
                    [1,5,1]
                    [4,2,1]             
        */
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int j=1;j<n;j++){
            dp[0][j] = dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++){
            dp[i][0] = dp[i-1][0]+grid[i][0];
        }        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         cout<<dp[i][j]<<",";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return dp[m-1][n-1];
    }
};