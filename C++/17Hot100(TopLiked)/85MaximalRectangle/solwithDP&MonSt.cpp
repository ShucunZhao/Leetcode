class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        //Step1: Covert char matrix to dp array.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') dp[i][j] = 1;
            }
        }
        //Step2: Count each height in dp from top to down.
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(dp[i-1][j]!=0&&dp[i][j]==1){
                    dp[i][j] = dp[i-1][j]+1;
                }  
            }
        }
        //Step3: Change the question to find the max rectangle 
        //       that constructed by each row of hitograms.
        stack<int> st;//This stack is a monotonous ascending stack which store the index of each base in histogram of row.
        //st.push(-1);//Base case which can treat as left edge.
        /*
            Ans: 1    2*(1-(-1)-1)=2, 2*(3-(1)-1)=2, 1*(5-1-1)=3;
            st: -1, 1 3 4 size   
            val: 0  0  
            i: -1   0 1 2 3 4  size
                0   
                    2,0,2,1,1,
                    3,1,3,2,2,
                    4,0,0,3,0,
        */
        int ans = 0;
        for(int row=0;row<m;row++){//Traverse each row of dp(Histogram)
            st.push(-1);//Base case which can treat as left edge, need to set this edge case when traverse each row.
            dp[row].push_back(0);//Add a zero in the last pos of each row.
            for(int i=0;i<=n;i++){//Find max rectangle(i can be equal to n because we add a 0 at last)
                if(i==0||dp[row][i]>=dp[row][st.top()]){
                    st.push(i);
                }
                else if(dp[row][i]<dp[row][st.top()]){
                    while(st.top()!=-1&&dp[row][i]<dp[row][st.top()]){
                        int curH = dp[row][st.top()];
                        st.pop();
                        int curW = i-st.top()-1;
                        ans = max(ans, curH*curW);
                    }
                    st.push(i);
                }
            }
            // cout<<"ans:"<<ans<<endl;
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