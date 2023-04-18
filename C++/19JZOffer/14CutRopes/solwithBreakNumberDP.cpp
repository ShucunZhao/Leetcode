class Solution {
public:
    /*
        dp[i]: the max product we can get of number i.
        The corner case of 2 and 3 because it must cut at least one time(m>1):
            if i ==2 return 1;
            if i ==3 return 2;
            if i ==4 return 
        The initialization :
            dp[0]: not exist
            dp[1]: 1 (for all i>1 the first cut can be 1)
            dp[2]: 2 (because if cut 2 it would be smaller)
            dp[3]: 3 (because if cut 2 it would be smaller)
        Inference formula:
            dp[i] = max(dp[j]*dp[i-j], dp[i]) (j from 2 to i/2);    


    */
    int cutRope(int number) {
        if(number==2) return 1;
        if(number==3) return 2;
        vector<int> dp(number+1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<=number;i++){
            for(int j=1;j<=(i/2);j++){
                dp[i] = max(dp[i], dp[i-j]*dp[j]);
            }
        }
        return dp[number];
    }
};