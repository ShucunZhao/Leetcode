class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                string sub = s.substr(j, i-j);
                if(wordSet.count(sub)!=0&&dp[j]==1){
                    dp[i] = 1;
                }
            }
        }
        return dp[s.size()];
    }
};