/*
 * dp[i][j]: If the interval [i,j] is palindrom, i point to head while j point to tail.
 * Infer formula: if s[i]!=s[j]: dp[i][j] = false.
                  else s[i]==s[j] has three cases: 
                       I.i is equal to j which means it's palindrom, so dp[i][j] = true.
                      II.j is equal to i+1 which also is palindrom, so dp[i][j] = true.
                     III.j is larger than i+1 we need analyze:
                                                      if dp[i+1][j-1] is true then dp[i][j] is true.
 * Initialization: all dp should be inital as false at first.
 * Iterate order: From infer formula we can see dp[i][j] should be infered by dp[i+1][j-1] which is on the lower left position,
                  so that we should iterate from bottom to top and from left to right.
 * Print dp to debug.           
 */
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), 0));
        int ans = 0;
        for(int i=s.size()-1;i>=0;i--){//Iterate from bottom to top:
            for(int j=i;j<s.size();j++){//Iterate from left to right:
                if(s[i]==s[j]){
                    if(j-i<=1){
                        dp[i][j] = 1;
                        ans++;
                    }
                    else if(dp[i+1][j-1]){
                        dp[i][j] = 1;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};