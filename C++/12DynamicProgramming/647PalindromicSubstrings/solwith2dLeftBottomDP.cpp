class Solution {
public:
    int countSubstrings(string s) {
        /*
            We use 2d DP to record if the current substring whose range if from i to j is palindrome and
            use a counter to store the number of palindrome in string s:

                  * a b c 
                a
                b
                c  
            dp[i][j]: if current substring s[i,j] is palindrome.
            if(s[i]==s[j]) there are three cases:
                case1: i==j which means is a single char that is a palindrome:
                    dp[i][j] = true and the counter++;
                case2: i+1==j which means is a double char like "aa" that is also a palindrome:
                    dp[i][j] = true and the counter++;
                case3: i+1<j which need to refer if dp[i+1][j-1] is a palindrome to determine dp[i][j]:
                    if(dp[i+1][j-1]==ture){
                        dp[i][j] = true;
                        counter++;
                    }
            The initialization: set all dp into false at first, and from inference formula we know should
            traverse the string from left-bottom coner.
        */
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        int cnt = 0;
        //"aaaaa"
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){//KeyPoint here! The j should begin at i rather 0 because the substring is from i to j: s[i,j].
                if(s[i]==s[j]){
                    if(j-i<=1){
                        dp[i][j] = true;
                        cnt++;
                    }
                    else{
                        if(dp[i+1][j-1]){
                            dp[i][j] = true;
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};