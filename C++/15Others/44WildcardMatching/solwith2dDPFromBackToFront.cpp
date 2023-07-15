class Solution {
public:
    bool isMatch(string s, string p) {
        /*
            Sol with 2d dp, and this question we need to think from back to front.
            dp[i][j] represent if the substring from i to end in s can match the substring from j to end in p.

                   i  
            s: "adcebb"
                   j
            p: " *a*bb"

            Infer formula:
                if(the current pos matched): bool curMatch = (s[i]==p[j])||(p[j]=='?')||(p[j]=='*');
                then deal with the most complex situation that the p[j] is '*':
                    There are two cases:
                                case1: p[j] '*' match nothing in s, so dp[i][j] = dp[i][j+1]
                                case1: p[j] '*' match more than one char in s, so dp[i][j] = curMatch&&dp[i+1][j]
                if(p[j]=='*'){
                    dp[i][j] = dp[i][j+1]||(curMatch&&dp[i+1][j])
                }
                else{
                    dp[i][j] = curMatch&&dp[i+1][j+1]
                }

            At the position
        */
        vector<vector<bool> > dp(s.size()+1, vector<bool>(p.size()+1, false));
        for(int i=s.size();i>=0;i--){
            for(int j=p.size();j>=0;j--){
                if(i==s.size()&&j==p.size()){
                    dp[i][j] = true;
                    continue;
                }
                bool curMatch = (i!=s.size())&&(j!=p.size())&&((s[i]==p[j])||(p[j]=='?')||(p[j]=='*'));
                if(j!=p.size()&&p[j]=='*'){
                    dp[i][j] = dp[i][j+1]||(curMatch&&dp[i+1][j]);
                }
                else{
                    dp[i][j] = curMatch&&dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};