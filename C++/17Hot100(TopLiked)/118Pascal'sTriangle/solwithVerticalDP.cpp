class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        /*
              [1],
              [1,1],
              [1,2,1],
              [1,3,3,1],
              [1,4,6,4,1]              
        */
        vector<vector<int> > ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++){
            int size = i+1;
            vector<int> path(size);
            for(int j=0;j<size;j++){
                if(j==0||j==size-1){
                    path[j] = 1;
                }
                else{
                    path[j] = ans[i-1][j]+ans[i-1][j-1];
                }
            }
            ans.push_back(path);
        }
        return ans;
    }
};