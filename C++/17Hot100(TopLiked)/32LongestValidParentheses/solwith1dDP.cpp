class Solution {
public:
    int longestValidParentheses(string s) {
        /*
                  i
            s  = ")()())"
            dp:    0 0

            dp[i]: the length of longest valid parantheses of string that ends as pos i.

            so all substring ends as '(' is not a valid paranthese so dp of it is 0.

            if(i-dp[i-1]>0&&s[i-dp[i-1]-1]=='('){
                dp[i] = 2+dp[i-1] + (i-dp[i-1]-2>-1?dp[i-dp[i-1]-2]:0)
            }
            
        */
        vector<int> dp(s.size());
        int ans = 0;
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                if(i-dp[i-1]>0&&s[i-dp[i-1]-1]=='('){
                    dp[i] = 2 + dp[i-1] + ((i-dp[i-1]-2)>-1?dp[i-dp[i-1]-2] : 0);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};