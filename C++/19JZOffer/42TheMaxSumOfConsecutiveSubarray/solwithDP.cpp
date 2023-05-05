class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        /*
            [1,-2,3,10,-4,7,2,-5]

            dp[i]: the max sum of subarray when traverse in pos i.

            if(nums[i]>dp[i-1]){
                dp[i]=nums[i];
            }
            else{
                dp[i] = dp[i-1]+nums[i]
            }

            max: 13

            dp[0]: 1
            dp[1]: -1
            dp[2]: 3
            dp[3]: 13
            dp[4]: 9
            dp[5]: 16
            dp[6]: 18
            dp[7]: 13
        */
        if(array.size()==1) return array[0];
        vector<int> dp(array.size());
        dp[0] = array[0];
        int ans = dp[0];
        for(int i=1;i<array.size();i++){
            if(array[i]>dp[i-1]&&dp[i-1]<0){
                dp[i] = array[i]; 
            }
            else{
                dp[i] = dp[i-1]+array[i];
            }
            //cout<<"dp["<<i<<"]:"<<dp[i]<<endl;
            ans = max(dp[i], ans);
        }
        return ans;
    }
};