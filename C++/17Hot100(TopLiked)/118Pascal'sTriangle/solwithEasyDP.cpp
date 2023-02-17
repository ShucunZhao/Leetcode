class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
            Input:  numRows = 5
            Output: [[1],               row: 1
                     [1,1],                  2   
                     [1,2,1],                3   
                     [1,3,3,1],              4
                     [1,4,6,4,1]]            5
                j:    0 1 2 3 4 
        */
        vector<vector<int> > dp;
        for(int i=0;i<numRows;i++){
            int row = i+1;
            vector<int> path(row);
            for(int j=0;j<row;j++){
                if(j==0||j==row-1){
                    path[j] = 1;
                }
                else{
                    path[j] = dp[i-1][j-1] + dp[i-1][j];
                }
            }
            dp.push_back(path);
        }
        /*
        for(int i=0;i<numRows;i++){
            for(int j=0;j<i+1;j++){
                // cout<<"dp["<<i<<"]"<<"["<<j<<"]:"<<dp[i][j]<<endl;
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        */
        return dp;
    }
};