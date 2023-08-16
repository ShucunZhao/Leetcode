class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        /*
            matrix = [["1","0","1","0","0"],
                      ["1","0","1","1","1"],
                      ["1","1","1","1","1"],
                      ["1","0","0","1","0"]]
            -----------------------------------
            matrix = [["1","0","1","0","0"],
                      ["2","0","2","1","1"],
                      ["3","1","3","2","2"],
                      ["4","0","0","3","0"]]          
        */
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n));
        for(int j=0;j<n;j++) dp[0][j] = matrix[0][j]-'0';
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]!='0'){
                    dp[i][j] = dp[i-1][j]+1;
                }
            }
        }
        for(int i=0;i<m;i++){
            dp[i].insert(dp[i].begin(), -1);
            dp[i].push_back(-1);
        }
        int ans = 0;
        for(int i=0;i<dp.size();i++){
            stack<int> st;//monontonic ascending stack store index.
            st.push(0);
            for(int j=1;j<dp[0].size();j++){
                while(dp[i][j]<dp[i][st.top()]){
                    int H = dp[i][st.top()];
                    st.pop();
                    int W = j-st.top()-1;
                    ans = max(ans, H*W);
                }
                st.push(j);
            }
        }
        /*
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
        cout<<endl;
        */
        return ans;
    }
};