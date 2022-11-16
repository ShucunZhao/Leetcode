/*
 * DP array: dp[i][j][k] - The most amount of the No."i" string in str set can be choosed when
             puting most "j" 0 and most "k" 1 into knapsack zero's m and one's n. 
 * Inference formula: I. If 0's amount > m or 1's amount > n:
                         dp[i][j][k] = dp[i-1][j][k]
                      II.else dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][m-(dp[i-1]'s 0)][n-(dp[j-1]'s 1)]+1)
 * Initialization: dp[0][x][x] = 0, d[x][0][0] = 0
 * Iterate order: From front to back
 * Print dp array to debug.
 */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int> > > dp(strs.size()+1, vector<vector<int> >(m+1, vector<int>(n+1, 0)));
        for(int i=1;i<=strs.size();i++){
            int zero  = 0, one = 0;
            for(char c : strs[i-1]){
                if(c=='0'){
                    zero++;
                }
            }
            one = strs[i-1].size() - zero;
            // cout<<"z:"<<zero<<"o:"<<one<<endl;
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    if(zero>j||one>k){
                        dp[i][j][k] = dp[i-1][j][k]; 
                    }
                    else{
                        dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-zero][k-one]+1);
                    }
                }
            }
        }
        // for(int i=0;i<=strs.size();i++){
        //     for(int j=0;j<=m;j++){
        //         for(int k=0;k<=n;k++){
        //             cout<<"dp["<<i<<"]"<<"["<<j<<"]"<<"["<<k<<"]:"<<dp[i][j][k]<<endl;
        //         }
        //     }
        // }
        return dp[strs.size()][m][n];
    }
};