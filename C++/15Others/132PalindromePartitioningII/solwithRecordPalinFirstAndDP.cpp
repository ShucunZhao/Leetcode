class Solution {
public:
    int minCut(string s) {
        /*
            First: record the valid substring palindrome by isValid dp array:
                isValid[i][j] is if the s[i,j] is palindrome.
            Initialization:
                isValid[i][i] is true, which means each single char is palidrome.
                others we can set false at first.
            Inference formula:
                if s[i]!=s[j] just jump.
                if s[i]==s[j], there are three cases:
                    Case1: "aa", j-i=1
                    Case2： "aba", i+1=j-1 ---> j-i=2
                    Case3: isValid[i][j] = isValid[i+1][j-1]  (Infer formula)
            From formula we know the traverse should start from bottom to top 
             and from left to right, and always keep j>=i.
        */
        vector<vector<bool> > isValid(s.size(), vector<bool>(s.size(), false));
        for(int i=0;i<s.size();i++) isValid[i][i] = true;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    if(j-i<=2) isValid[i][j] = true;
                    else isValid[i][j] = isValid[i+1][j-1];
                }
            }
        }
        /*********Do the key cutting step***************/
        /*
           dp[0]: 0
           dp[1]: 0

                  j
            s = "aab"
                   i
        */
        vector<int> dp(s.size(), INT_MAX);
        for(int i=0;i<s.size();i++){
            if(isValid[0][i]){
                dp[i] = 0;
                continue;
            }
            for(int j=0;j<i;j++){
                if(isValid[j+1][i]){
                    dp[i] = min(dp[i], dp[j]+1);
                }
            }
        }
        return dp[s.size()-1];
    }
};