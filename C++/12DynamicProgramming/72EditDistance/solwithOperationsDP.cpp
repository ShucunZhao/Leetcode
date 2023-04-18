class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            dp[i][j]: the minimum operation times when is in position i in word2, posisition j in word2.
            
                if current char is same we do nothing:
                    dp[i][j] = dp[i-1][j-1]
                else  there are three cases when operating:
                    case1 - Insert:
                            dp[i][j] = dp[i-1][j]+1(insert in word2) or dp[i][j-1]+1(insert in word1)
                    case2 - Delete:
                            Has the same operaton times as Insert, so:
                            dp[i][j] = dp[i-1][j]+1(delete in word2) or dp[i][j-1]+1(delete in word1)
                    case3 - Replace:
                            dp[i][j] = dp[i-1][j-1] + 1
                So the infer formula is : 
                                dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1);
            Initialization:
                    dp[0][0] = 0
                    dp[i][0] = i, dp[0][j] = j
                word1:  * h o r s e
            word2:   *  0 1 2 3 4 5
                     r  1 1 1 1 1 1
                     o  2 2 1 2 2 2 
                     s  3 2 2 2 2 3  
        */
        vector<vector<int> > dp(word2.size()+1, vector<int>(word1.size()+1));
        for(int i=0;i<=word2.size();i++) dp[i][0] = i;
        for(int j=0;j<=word1.size();j++) dp[0][j] = j;
        for(int i=1;i<=word2.size();i++){
            for(int j=1;j<=word1.size();j++){
                if(word2[i-1]==word1[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(dp[i-1][j-1]+1, min(dp[i-1][j]+1, dp[i][j-1]+1));
                }
            }
        }
        return dp[word2.size()][word1.size()];
    }
}; 