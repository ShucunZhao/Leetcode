class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int> > dp(matrix.size(), vector<int>(matrix[0].size()));
        for(int j=0;j<matrix[0].size();j++) dp[0][j] = matrix[0][j]-'0';
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1'){
                    dp[i][j] = dp[i-1][j]+1;
                }
            }
        }
        for(int i=0;i<dp.size();i++){
            dp[i].insert(dp[i].begin(), -1);
            dp[i].push_back(-1);
        }
        /*
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
        */
        int ans = 0;
        for(int i=0;i<dp.size();i++){
            stack<int> st;//Acending monotonic stack to store the index of element.
            st.push(0);
            for(int j=1;j<dp[0].size();j++){
                while(dp[i][j]<dp[i][st.top()]){
                    int H = dp[i][st.top()];
                    st.pop();
                    int W = j-st.top()-1;
                    // cout<<"H:"<<H<<",W:"<<W<<endl;
                    if(W>=H){//KeyPoint here! If the width larger than height means it must can construct a square.
                        ans = max(ans, H*H);
                    }
                }
                st.push(j);
            }
        }
        return ans;
    }
};