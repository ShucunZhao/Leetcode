class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int> > dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        // int ans = 0;
        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                // ans = max(ans, dp[i][j]);//Don't need this step because the final element will be the maximum.
            }
        }
        // return ans;
        return dp[text1.size()][text2.size()];
    }
};