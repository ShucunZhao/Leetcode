class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            Sol with move the zero to first row and col,
            then using first row to deal with the columns case,
            while using first col to deal with the rows case.
            At last, use two flag the record if we should deal with
            the first row and column situation.
        */
        //These two flags are used for record the first row and column situations.
        bool firstRow = false;
        bool firstCol = false;
        //Step1: move zero.
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    if(i==0){
                        firstRow = true;
                    }
                    if(j==0){
                        firstCol = true;
                    }
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //Step2: according to the first row zero cases to deal with each column except first column.
        for(int j=1;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                for(int i=1;i<matrix.size();i++){
                    matrix[i][j] = 0;
                }
            }
        }
        //Step3: according to the first column zero cases to deal with each row except first row.
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                for(int j=1;j<matrix[0].size();j++){
                    matrix[i][j] = 0;
                }
            }
        }
        //Step4: deal with the first row and column situations.
        if(firstRow){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j] = 0;
            }
        }
        if(firstCol){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0] = 0;
            }
        }
        return;
    }
};