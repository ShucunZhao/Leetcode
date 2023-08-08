class Solution {
public:
    int nthUglyNumber(int n) {
        /*
            sol with DP:
                dp[t] = min(dp[i]*2, dp[j]*3, dp[k]*5)
                then update the i,j and k.
        */
        int i = 0, j = 0, k = 0;
        vector<int> ans = {1};
        for(int t=0;t<n-1;t++){
            int cur = min(min(ans[i]*2, ans[j]*3), ans[k]*5);
            // cout<<cur<<endl;
            ans.push_back(cur);
            if(cur==ans[i]*2) i++;
            if(cur==ans[j]*3) j++;
            if(cur==ans[k]*5) k++;
        }
        // return -1;
        return ans.back();
    }
};