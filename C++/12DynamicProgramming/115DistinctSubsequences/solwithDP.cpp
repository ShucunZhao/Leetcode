/*
 * dp[i][j]: The number of cases subsequence that end with index i in original string can generate 
             the subsequence that end with index j in target string.
 * Infer formula: if s[i-1] == t[j-1] will have two cases:
                      I.Use s[i-1]: dp[i][j] should be dp[i-1][j-1], because if s[i-1] is equal to t[i-1] 
						that means adding these two characters will not affect the result, which is also dp[i-1][j-1].
                      II.Don't use s[i-1] and jump into next s[i]: dp[i][j] should be dp[i-1][j]
                      then: dp[i][j] = dp[i-1][j-1] + dp[i-1][j].
                  else: because it is not equal then you must jump current s[i-1] to s[i]:
                      dp[i][j] = dp[i-1][j]
 * Initialization: dp[0][xxx not 0] = 0: use empty set to generate not empty set will get 0.
                   dp[xxx 0 or not][0] = 1: use anything to generate empty set will get 1.
 * Iterate: From front to back.
 * Print dp to debug.
 */
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t> > dp(s.size()+1, vector<uint64_t>(t.size()+1, 0));//Use unit64_t here if use int
                                                                                //will get integer overflow.
        for(int i =0;i<s.size();i++){
            dp[i][0] = 1;
        }        
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(int i=0;i<=s.size();i++){
        //     for(int j=0;j<=t.size();j++){
        //         cout<<"dp["<<i<<"]"<<"["<<j<<"]:"<<dp[i][j]<<endl;
        //     }
        // }
        return dp[s.size()][t.size()];
    }
};
