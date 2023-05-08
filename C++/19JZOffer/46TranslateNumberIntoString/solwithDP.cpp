
class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        /*
            dp[i]: the number of decode ways when in position i of string nums.
            1 2 3
            a (1)
            ab;l (2)
            abc;lc;ax (3) 
            There are two cases in position i:
                Case1: the nums[i] is treated as one decode ans, so the number of ans is equal
                        to the last one which is dp[i] = dp[i-1].
                Case2: If the nums[i-1] and nums[i] is also meet the 1-26 conditions, it's another
                        ans so the dp[i] is also can be dp[i] = dp[i-2]
            To sum up: Inference formula:
                if(nums[i-1] and nums[i] is meet the 1-26){
                    dp[i] = dp[i-1]+dp[i-2]
                }
                else{
                    dp[i] = dp[i-1]
                }
            Initialization:
              dp[0] = 1;
              dp[1] = 2 if (nums[0]nums[1] meet 1-26) else dp[1] = 1;
              dp[2] = ......
        */
        if(nums=="0") return 0;
        if(nums=="10"||nums=="20") return 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]=='0'&&nums[i-1]!='1'&&nums[i-1]!='2'){
                return 0;
            }
        }
        vector<int> dp(nums.size());
        dp[0] = 1;
        if((nums[0]=='1'&&nums[1]!='0')||(nums[0]=='2'&&nums[1]>'0'&&nums[1]<'7')) dp[1] = 2;
        else dp[1] = 1;

        for(int i=2;i<nums.size();i++){
            if((nums[i-1]=='1'&&nums[i]!='0')||(nums[i-1]=='2'&&nums[i]>'0'&&nums[i]<'7')){
                dp[i] = dp[i-2] + dp[i-1];
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        return dp[nums.size()-1];
    }
};