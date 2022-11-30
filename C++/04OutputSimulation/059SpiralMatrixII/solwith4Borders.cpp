class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));
        int left = 0, right = n-1, up = 0, down = n-1;
        int cnt = 1;
        while(1){
            for(int i=up;i<=right;i++){
                ans[up][i] = cnt;
                // cout<<"ans["<<up<<"]"<<"["<<i<<"]"<<ans[up][i]<<endl;
                cnt++;
            }
            if(++up>down) break;
            for(int j=up;j<=down;j++){
                ans[j][right] = cnt;
                // cout<<"ans["<<j<<"]"<<"["<<right<<"]"<<ans[j][right]<<endl;
                cnt++;
            }
            if(--right<left) break;
            for(int k = right;k>=left;k--){
                ans[down][k] = cnt;
                // cout<<"ans["<<down<<"]"<<"["<<k<<"]"<<ans[down][k]<<endl;
                cnt++;
            }
            if(--down<up) break;
            for(int l = down;l>=up;l--){
                ans[l][left] = cnt;
                cnt++;
            }
            if(++left>right) break;
        }
        return ans;
    }
};