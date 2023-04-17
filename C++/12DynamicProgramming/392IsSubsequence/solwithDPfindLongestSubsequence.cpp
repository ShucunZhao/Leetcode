class Solution {
public:
    bool isSubsequence(string s, string t) {
        /*
            Sol: find the longest subsequence to determine if it's length is equal to string.
            dp[i][j]: the longest length of subsequence when i in string s and j in string t.
                
              t: * a h b g d c
               * 0 0 0 0 0 0 0
            s: a 0 1 1 1 1 1 1
               b 0 1 1 2 2 2 2
               c 0   

        */  
        vector<vector<int> > dp(s.size()+1, vector<int>(t.size()+1));
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(s[i-1]==t[j-1]){
                    dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
                }
            }
        }
        /*
        for(int i=0;i<s.size();i++){
            for(int j=0;j<t.size();j++){
                cout<<dp[i][j];
            }
            cout<<endl;
        }
        */
        return s.size()==dp[s.size()][t.size()];
    }
};