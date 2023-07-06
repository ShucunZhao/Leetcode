class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            matrix = [1,1,1]
                     [1,0,1]
                     [1,1,1]
        */
        vector<bool> flagRow(matrix.size(),false);
        vector<bool> flagCol(matrix[0].size(), false);
        // vector<vector<bool> > flag(matrix.size(), vector<bool>(matrix[0].size(), false));
        int row = 0, col = 0;
        for(int i=row;i<matrix.size();i++){
            for(int j=col;j<matrix[0].size();j++){
                // if(flag[])
                if(matrix[i][j]==0){
                    flagRow[i] = true;
                    flagCol[j] = true;
                    // break;
                }
            }
            // col++;
        }
        /*
        cout<<"Row:";
        for(bool Row : flagRow) cout<<Row<<",";
        cout<<endl;
        cout<<"Col:";
        for(bool Col : flagCol) cout<<Col<<",";
        cout<<endl;
        */
        for(int i=0;i<flagRow.size();i++){
            if(flagRow[i]){
                for(int j=0;j<matrix[0].size();j++) matrix[i][j] = 0;
            }
        }
        for(int j=0;j<flagCol.size();j++){
            if(flagCol[j]){
                for(int i=0;i<matrix.size();i++) matrix[i][j] = 0;
            }
        }
    }
};