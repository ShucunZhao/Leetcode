/* So hard:
 * Step1: Convert the question into an 01 package question:
          If Negative set sum called minus while positive set sum called plus and sum of nums set called sum, we know:
          I.plus - minus = target II.plus + minus = sum
          so that minus = (sum-target)/2
          therefore we can treat this question as select object from nums set to fill package minus.
 * Step2: The special edge case: 
          (sum-target) must be even and target shouldn't larger than sum.
 * Step3: Define the 2D dp array:
          dp[i][j]: The meeting cases if choose previous i(including i) objects to fill package which size is j exactly.
 * Step4: Inference formula:
          I.  If current object larger than current package size j which means cannot choose nums[i]:
                 dp[i][j] = dp[i-1][j]
          II. If current object smaller/equal to j:
                 II.I  Don't choose nums[i] : dp[i-1][j]
                 II.II Choose nums[i]: dp[i-1][j-nums[i]]
                Therefore: dp[i][j] = caseII.I + caseII.II = dp[i-1][j] + dp[i-1][j-nums[i]]
 * Step5: Initialization:
          You need to consider the situations below:
            I.   When the j is 0, the case should be 1 because you can put nothing into a empty package, which should be treated as a case.
            II.  Initialize the j is equal to nums[0] to be 1.
            III. When the nums[0] is also zero, you need to initial dp[0][nums[0]] into 2: 
                 Because wether put nums[0] into package or not is also meet the condition.
 * Step6: Iterator order: from front to back and the value of last dp element is answer(dp[nums.size()-1][minus]).
 */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        target = abs(target);//Because the use of symbol "-" and "+" can change so we make targer to be absolute value. 
        //Spte2: Two edge cases:
        if(target>sum) return 0;
        if((sum-target)%2!=0) return 0;
        int minus = (sum-target)/2;
        vector<vector<int> > dp(nums.size(), vector<int>(minus+1, 0));
        //Two Key points of initialization here:
        dp[0][0] = 1;
        if(minus>=nums[0]){
            if(nums[0]==0) dp[0][nums[0]] = 2;
            else dp[0][nums[0]] = 1;
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<=minus;j++){
                if(j<nums[i]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]];
                }
            }
        }
        //Step7: Test your dp array output to debug:
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<=minus;j++){
        //         cout<<"dp["<<i<<"]"<<"["<<j<<"]"<<dp[i][j]<<endl;
        //     }
        // }        
        return dp[nums.size()-1][minus];
    }
};