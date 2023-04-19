class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
            dp[i][j]: the length of longest palindrome subsequence of string s[i,j] from i to j.
            if(s[i]==s[j]){
                if(i==j){
                    dp[i][j] = 1;
                }
                else if(i+1==j){
                    dp[i][j] = 2;
                }
                else{
                    dp[i][j] = dp[i+1][j-1]+2;
                }
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
            }
            There are two cases in inference formula:
                Case1 when s[i]==s[j]:
                    From above we know the infer formula need to infer from left-bottom to right-up.
                Case2 when s[i]!s[j]:
                    When we draw the table below we know, when s[i]!s[j] we need to get the max from 
                    left-pos which is dp[i-1][j] and down-pos which is dp[i+1][j] to get current dp[i][j]:

            s = "bbbab"
               01234
        
            dp: j  0 1 2 3 4
                i  0  
                    1
                    2
                    3     1 1
                    4       1 

            Initialization: each time the s[i] will be equal to s[j] so we just set all dp as 0 at first is ok.
        */
        //int ans = 0;
        vector<vector<int> > dp(s.size(), vector<int>(s.size()));
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    if(i==j){
                        dp[i][j] = 1;
                    }
                    else if(i+1==j){
                        dp[i][j] = 2;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1]+2;
                    }
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
                //ans = max(ans, dp[i][j]);
            }
        }
        return dp[0][s.size()-1];
    }
};