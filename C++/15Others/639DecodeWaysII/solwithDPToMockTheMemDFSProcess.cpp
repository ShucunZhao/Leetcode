class Solution {
public:
    int numDecodings(string s) {
        /*
            dp[i]: the decode ways from the first i chars in string s.
            Inference formula:
                Case1:
                    s[i-2]s[i-1]
                       *     *
                    if(s[i]!=0){
                        dp[i] = 9*dp[i-1] + 15*dp[i-2];
                    }
                Case2:
                    s[i-2]s[i-1]
                       *     X
                    if(s[i-1]=='0'){
                        dp[i] = 2*dp[i-2];
                    }
                    else{
                        dp[i] = 9*dp[i-1];
                        if(s[i-1]>='7'){
                            dp[i]+=dp[i-2];
                        }
                        else{
                            dp[i]+=2*dp[i-2];
                        }
                    }
                Case3:    
                    s[i-2]s[i-1]
                       X     *
                    if(s[i-2]=='1'){
                        dp[i] = 9*dp[i-2];
                    }   
                    else if(s[i-2]=='2'){
                        dp[i] = 6*dp[i-2]
                    }
                    if(s[i-2]!='0'){
                        dp[i]+=dp[i-1]
                    }
                Case4:(Same as 91:)
                    s[i-2]s[i-1]
                      X     X
        */
        if(s[0]=='0') return 0;
        int mod = 1e9+7;
        vector<long long> dp(s.size()+1);
        dp[0] = 1;
        dp[1] = s[0]=='*'?9:1;
        for(int i=2;i<=s.size();i++){
            char first = s[i-2];
            char second = s[i-1];
            //For dp[i-1]:
            if(second=='*'){
                dp[i]+=9*dp[i-1];
            }
            else if(second>'0'){
                dp[i]+=dp[i-1];
            }
            //For dp[i-2]:
            if(first=='*'){
                if(second=='*'){
                    dp[i]+=15*dp[i-2];
                }
                else if(second<='6'){
                    dp[i]+=2*dp[i-2];
                }
                else{
                    dp[i]+=dp[i-2];
                }
            }
            else if(first=='1'||first=='2'){
                if(second=='*'){
                    if(first=='1'){
                        dp[i]+=9*dp[i-2];
                    }
                    else{
                        dp[i]+=6*dp[i-2];
                    }
                }
                else if(((first-'0')*10+(second-'0'))<=26){
                    dp[i]+=dp[i-2];
                }
            }
            dp[i]%=mod;
        }
        return dp[s.size()];
    }
};