class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        /*
            sol with treating the lines as the common subsequence that should find the longest answer:
            dp[i][j]: the longest common subsequence when in position i of nums2 and position j of nums1.

            nums1:(j)     1  4  2
            nums2:(i)  1  1  1  1 
                       2  1  1  2
                       4  1  2  2

            Initialization:
                dp[0][x] = 1 from x to nums1.size()-1 if dp[0][x]==nums2[0] else dp[0][x] = 0;    
                dp[x][0] = 1 from x to nums2.size()-1 if dp[x][0]==nums1[0] else dp[x][0] = 0; 

            for(i from 1 to nums2.size()){
                for(j from 1 to nums1.size()){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
                    if(nums2[i]==nums1[j]){
                        dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
                    }
                }
            }          
            return dp[nums2.size()-1][nums1.size()-1]
        */
        vector<vector<int> > dp(nums2.size(), vector<int>(nums1.size(), 0));
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]==nums1[0]){
                while(i<nums2.size()){
                    dp[i][0] = 1;
                    i++;
                }
            }
        }
        for(int j=0;j<nums1.size();j++){
            if(nums1[j]==nums2[0]){
                while(j<nums1.size()){
                    dp[0][j] = 1;
                    j++;
                }
            }
        }    
        for(int i=1;i<nums2.size();i++){
            for(int j=1;j<nums1.size();j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(nums2[i]==nums1[j]){
                    dp[i][j] = max(dp[i-1][j-1]+1, dp[i][j]);
                }
            }
        }   
        return dp[nums2.size()-1][nums1.size()-1];
    }
};