class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int maxValue(vector<vector<int> >& grid) {
        // write code here
        /*
            [  0  0 0 0 
               0 [1,4,5],
               0 [2,9,10],
               0 [6,11,12]
            ]
            From top-left to bottom-right:
            dp[i][j]: the max we can get when in position grid[i][j]
            Inference:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j]
            
        */
        vector<vector<int> > dp(grid.size()+1, vector<int>(grid[0].size()+1, 0));
        for(int i=1;i<=grid.size();i++){
            for(int j=1;j<=grid[0].size();j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[grid.size()][grid[0].size()];
    }
};