class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        //Step1:
        for(int j=0;j<n;j++){
            if(matrix[0][j]=='1') dp[0][j] = 1;
        }
        //Step2:
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    if(dp[i-1][j]!=0){
                        dp[i][j] = dp[i-1][j]+1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
            }
        }
        stack<int> st;//Monotonous acending stack to save index.
        /*
        st: -1 0 
        i:      0 1 2 3 4    5
                1,0,1,0,0,   0
                2,0,2,1,1,   0
                3,1,3,2,2,   0
                4,0,0,3,0,   0
        */
        int ans = 0;
        for(int i=0;i<m;i++){
            st.push(-1);
            dp[i].push_back(0);
            for(int j=0;j<=n;j++){
                if(st.top()==-1||dp[i][j]>=dp[i][st.top()]){
                    st.push(j);
                }
                else{
                    while(st.top()!=-1&&dp[i][j]<dp[i][st.top()]){
                        int curH = dp[i][st.top()];
                        st.pop();
                        int curW = j-st.top()-1;
                        //cout<<"curH:"<<curH<<",";
                        //cout<<"curW:"<<curW<<endl;
                        if(curW>=curH){
                            ans = max(ans, curH*curH);
                        }
                    }
                    st.push(j);
                }
            }
        }
        /*
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<",";
            }
            cout<<endl;
        }
        */
        return ans;
    }
};