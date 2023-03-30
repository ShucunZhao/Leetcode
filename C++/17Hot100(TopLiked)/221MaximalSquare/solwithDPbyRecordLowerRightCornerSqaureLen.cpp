class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        /*
             matrix = [["1","0","1","0","0"],
                       ["1","0","1","1","1"],
                       ["1","1","1","1","1"],
                       ["1","0","0","1","0"]]

        dp[i][j]: Take the pos(i,j) as lower right corner to make the max length of square.
        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;(Must be where the matrix[i][j] is also '1'); 
        dp[0][x] = marix[0][x];
        dp[x][0] = matrix[x][0];
        for(i from 1 to m, j from 1 to n)   
        */
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        int maxL = 0;
        for(int i=0;i<m;i++){
            if(matrix[i][0]=='1'){
                dp[i][0] = 1;
                maxL = 1;
            } 
        }
        for(int j=0;j<n;j++){
            if(matrix[0][j]=='1'){
                dp[0][j] = 1;
                maxL = 1;
            } 
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    maxL = max(dp[i][j], maxL);
                }
            }
        }
        return maxL*maxL;
    }
};