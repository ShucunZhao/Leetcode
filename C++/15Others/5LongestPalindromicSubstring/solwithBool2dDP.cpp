class Solution {
public:
    string longestPalindrome(string s) {
        //dp[i][j]: If the string s[i,j] is palindrome, if yes: dp[i][j] = true else: dp[i][j] = false.
        //if s[i]=s[j]: 
        //      Case1: if(j-i<2) which means i=j: "a" or i+1=j: "aa" so this case if palindrome.
        //      Case2: if(j-i>=2) we need to judge dp[i+1][j-1], if s from i+1 to j-1 is palindrome(dp[i+1][j-1]=1)
        //              then dp[i][j] = ture like "ababa".
        //s:     "babad"
        //j:       0 1 2 3 4
        //dp:      b a b a d
        //    0 b  1  
        //    1 a    1
        //    2 b      1
        //    3 a        1 
        //    4 d          1
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), 0));
        int l=0, r=0, maxL=0;//Use maxL to record the longest length and l is left range r is right range. 
        for(int i=0;i<s.size();i++) dp[i][i] = 1;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    if(j-i<2){
                        dp[i][j] = 1;
                    }
                    else{
                        if(dp[i+1][j-1]){
                            dp[i][j] = 1;
                        }
                    }
                    if(dp[i][j]&&(j-i)>maxL){
                        maxL = j-i;
                        l=i;
                        r=j;
                    }
                }
            }
        }
        // cout<<"l:"<<l<<"r:"<<r<<endl;
        return s.substr(l, r-l+1);
        //return s.substr(l, r);//Cannot just write like this because the substr is copy the number of r elements from position l. 
        // return "";
    }
};