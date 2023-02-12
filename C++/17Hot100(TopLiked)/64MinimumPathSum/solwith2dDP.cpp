class Solution {
public:
    // void backtracking(){
    //     if(i){
    //         ans = min(ans, sum);
    //         return;
    //     }
    //     for(int i = start; i<g)
    // }
    int minPathSum(vector<vector<int>>& grid) {
        /*
           grid =   [[1,3,1],
                    [1,5,1],
                    [4,2,1]]
           ---------------------
            dp  =   [[1,4,5],
                     [2,7,6],
                     [6,
            dp[i][j]: the minimum path sum in pos grid[i][j].
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j] (i>1&&j>1)
        */
        vector<vector<int> > dp(grid.size(), vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for(int i=1;i<grid.size();i++){
            dp[i][0] = grid[i][0]+dp[i-1][0];
        }
        for(int j=1;j<grid[0].size();j++){
            dp[0][j] = grid[0][j]+dp[0][j-1];
        }
        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        // for(int i=0;i<grid.size();i++){
        //     for(int j=0;j<grid[0].size();j++){
        //         cout<<"dp["<<i<<"]["<<j<<"]:"<<dp[i][j]<<endl;
        //     }
        // }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};