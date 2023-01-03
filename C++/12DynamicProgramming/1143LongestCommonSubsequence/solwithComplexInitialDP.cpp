class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        bool flag1 = 0, flag2 = 0;
        for(int i=0;i<m;i++){
            if(!flag1&&text1[i]==text2[0]){
                flag1 = 1;
                dp[i][0] = 1;
            }
            if(flag1){
                dp[i][0] = 1;
            }
        }
        for(int j=0;j<n;j++){
            if(!flag2&&text1[0]==text2[j]){
                flag2 = 1;
                dp[0][j] = 1;
            }
            if(flag2){
                dp[0][j] = 1;
            }        
        }        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(text1[i]==text2[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<"dp["<<i<<"]"<<"["<<j<<"]:"<<dp[i][j]<<endl;
        //     }
        // }
        return dp[m-1][n-1];
    }
};