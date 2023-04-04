class Solution {
public:
    vector<int> countBits(int n) {
        /*
               i          ans:      
               0           0
               1           1
               2           10
               3           11
               4           100
               5           101
               6           110
               7           111
               8           1000
               9           1001      dp[9] = dp[8]+1
               10          1010      dp[10] = dp[10/2]
               so:
                if i is even:
                    dp[i] = dp[i/2]
                else i is odd:
                    dp[i] = dp[i-1]+1
                Initialization:
                dp[0] = 0;
                dp[1] = 1;     
        */
        if(n==0) return {0};
        if(n==1) return {0,1};
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            if(i%2==0){
                dp[i] = dp[i/2];
            }
            else{
                dp[i] = dp[i-1]+1;
            }
        }
        return dp;
    }
};