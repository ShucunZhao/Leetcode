class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
            dp[i]: if the first i char in string can spell the words in wordDict.
            word = "leetcode"
            if the first 0~j can spell, we just need to determine the if the j~i existed in wordDict.
            for(j from 0 to i){
                if(dp[j]&&wordDict.count(s.substr(j, i-j+1)!=0)){
                    dp[i] = 1;
                    break;
                }
            }
            Initialization:
            dp[0] = 1 because the first 0 string is ""(empty) can be used to spell any words.
        */
        unordered_set<string> wordSet;
        for(string str : wordDict){
            wordSet.insert(str);
        }
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i=1;i<=s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&wordSet.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};