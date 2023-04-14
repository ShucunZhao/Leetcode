class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        /*
                dp[i][j]: the longest subarray we can find when traverse nums1 in position i and
                          nums2 in position j.
                Initialization:
                        dp[0][x] = 1 that nums2[0] == nums1[x] from 0 to nums1.size().
                        dp[0][x] = 0 that nums2[0] != nums1[x] from 0 to nums1.size().
                        dp[x][0] = 1 that nums1[0] == nums2[x] from 0 to nums2.size().
                        dp[x][0] = 0 that nums1[0] != nums2[x] from 0 to nums2.size().

                ans = 0;
                for(int i from 1 to nums1.size()-1){
                    for(int j from 1 to nums2.size()-1){
                        if(nums1[i]==nums2[j]){
                            dp[i][j] = dp[i-1][j-1] + 1;
                        }
                        ans = max(ans, dp[i][j]);
                    }
                }        

             (dp:)  nums1:(i)    1 2 3 2 1 
                nums2:(j)     3  0 0 0 0 0
                              2  0 0 0 0 0
                              1  0 0 0 0 0
                              4  0 0 0 0 0
        */
        vector<vector<int> > dp(nums2.size(), vector<int>(nums1.size(), 0));
        int ans = 0;
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]==nums1[0]){
                dp[i][0] = 1;
                ans = 1;
            } 
        }
        for(int j=0;j<nums1.size();j++){
            if(nums1[j]==nums2[0]){
                dp[0][j] = 1;
                ans = 1;
            } 
        }
        for(int i=1;i<nums2.size();i++){
            for(int j=1;j<nums1.size();j++){
                if(nums2[i]==nums1[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};