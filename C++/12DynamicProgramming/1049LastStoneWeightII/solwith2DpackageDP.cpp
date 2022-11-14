class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        // cout<<"sum:"<<sum<<endl;
        int half = sum/2;
        // cout<<"half:"<<half<<endl;
        vector<vector<int> > dp(stones.size(), vector<int>(half+1, 0));
        for(int i=0;i<=half;i++){
            if(stones[0]<=i){
                dp[0][i] = stones[0];
            }
        }
        for(int i=1;i<stones.size();i++){
            for(int j=0;j<=half;j++){
                if(stones[i]>j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i]]+stones[i]);
                }
            }
        }
        // for(int i=0;i<stones.size();i++){
        //     cout<<"stones["<<i<<"]: "<<stones[i]<<endl;
        //     for(int j=0;j<half;j++){
        //         cout<<"dp["<<i<<"]"<<"["<<j<<"]: "<<dp[i][j]<<endl;
        //     }
        // }
        return sum-2*dp[stones.size()-1][half];
    }
};