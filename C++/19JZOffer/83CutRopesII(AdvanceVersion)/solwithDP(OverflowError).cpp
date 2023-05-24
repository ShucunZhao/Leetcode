class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param number long长整型 
     * @return long长整型
     */
    long long cutRope(long long number) {
        // write code here
        /*
        BaseCases:
                1: 1
                2: 1*1
                3: 1*1*1, 1*2
                4: 1*3,1*1*2,1*1*1*1,2*2,
        dp[i]: the max product we can get to cut the line.
            and we has j situations that j is from 1 to i/2:
        for(i from 4 to i){
            for(j from 1 to i/2){
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
            }
        }
        will get overflow error if the data size is too large(9223372036854775807)
        */
        if(number==2) return 1;
        if(number==3) return 2;
        vector<long long> dp(number+1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for(int i=4;i<=number;i++){
            for(int j=1;j<=i/2;j++){
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
            }
        }
        return dp[number];
    }
};