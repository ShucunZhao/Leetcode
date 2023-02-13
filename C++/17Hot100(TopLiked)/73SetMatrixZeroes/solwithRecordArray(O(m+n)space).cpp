class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int> > flag;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    flag.push_back({i,j});
                }
            }
        }
        if(flag.empty()) return;
        for(int x=0;x<flag.size();x++){
            for(int i=0;i<matrix.size();i++){
                matrix[i][flag[x][1]] = 0;
            }
            for(int j=0;j<matrix[0].size();j++){
                matrix[flag[x][0]][j] = 0;
            }
        }
        /*
        for(int i=0;i<flag.size();i++){
            cout<<"{"<<flag[i][0]<<","<<flag[i][1]<<"}"<<endl;
        }
        */
    }
};