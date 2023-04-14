class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        /*
            dp[i][j]: the longest subsequence(rather than subarray) in text1 position j,
                      text2 in pisition i.
            int ans = 0;
            Initialization:
                    dp[0][x] = 1(from x to end) and ans = 1 if text1[x]==text2[0], else dp[0][x] = 0;
                    dp[x][0] = 1(from x to end) and ans = 1 if text2[x]==text1[0], else dp[x][0] = 0.
            
            for(int i=1;i<text2.size();i++){
                for(int j=1;j<text1.size();j++){
                    if(text2[i]==text1[j]){
                        dp[i][j] = max(dp[i-1][j-1]+1, dp[i-1][j], dp[i][j-1]);//Difference between subarray, need to choose all maximum of before state to plus current 1.
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);//Difference between subarray, need to choose all maximum of before state.
                    }
                    ans = max(ans, dp[i][j]);
                }
            }

            (dp )
            text1(i):   b s b i n i n m
            text2(j): j 0 0 0 0 0 0 0 0 
                      m 0 0 0 0 0 0 0 1
                      j 0 0 0 0 0 0 0 1
                      k 0 0 0 0 0 0 0 1
                      b 1 1 1 1 1 1 1 1   
                      k 1 1 1 1 1 1 1 1
                      j 1 1 1 1 1 1 1 1 
                      k 1 1 1 1 1 1 1 1
                      v 1 1 1 1 1 1 1 1
        */
        vector<vector<int> > dp(text2.size(), vector<int>(text1.size(), 0));
        int ans = 0;
        for(int i=0;i<text2.size();i++){
            if(text2[i]==text1[0]){
                ans = 1;
                while(i<text2.size()){
                    dp[i][0] = 1;
                    i++;
                }
            }
        }
        for(int j=0;j<text1.size();j++){
            if(text1[j]==text2[0]){
                ans = 1;
                while(j<text1.size()){
                    dp[0][j] = 1;
                    j++;
                }
            }
        }
        for(int i=1;i<text2.size();i++){
            for(int j=1;j<text1.size();j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(text2[i]==text1[j]){
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
                }
                /*
                if(text2[i]==text1[j]){
                    dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+1);
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                */
                ans = max(dp[i][j], ans);
            }
        }
        return ans;        
    }
};