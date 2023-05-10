class Solution {
public:
    string longestPalindrome(string s) {
        /*
                s = "b a b a d"
                     0 1 2 3 4
                b 0  t  
                a 1    t
                b 2      t  
                a 3        t 
                d 4          t

        dp[i][j]: if it's a palindrome when traverse in position from i to j which substring is s[i,j].
        There are two different cases:
            case1: 
                if s[i]!=s[j] : dp[i][j] = false.
            case2:
                if s[i]==s[j]:
                    we need to check if dp[i+1][j-1] is palindrome like:  i  j
                                                                          abba
                    so dp[i][j] = dp[i+1][j-1]
                        So the inference formula is from left-down corner to current, so we need to traverse
                        from down to top(i is form s.size()-1 to 0) and from left to right(which is j, but j
                        must be always >= i so it's only can start from i to s.size()-1).
                    But there are few corner cases:
                        case1: if i+1==j-1 which is "aba" so that j-i == 2, dp[i][j] must be true.
                        case2: j-i=1 which is "aa" so that dp[i][j] also be true.
                        case3: other cases we can treat as dp[i][j] = dp[i+1][j-1]

        And each sigle char is a palindrome so that the initialization is:
            dp[x][x] = true, else false.
        */
        if(s.size()<2) return s;
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        int maxL = 0;
        string ans;
        for(int i=0;i<s.size();i++){
            dp[i][i] = true;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    if(j-i<=2){
                        dp[i][j] = true;
                    }
                    else{
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                /* Don't need to do this because we initialize it be false at first.
                else{
                    dp[i][j] = false;
                }
                */
                if(dp[i][j]&&(j-i+1)>maxL){
                    ans = s.substr(i, j-i+1);
                    maxL = (j-i+1);
                }
            }
        }
        return ans;
    }
};