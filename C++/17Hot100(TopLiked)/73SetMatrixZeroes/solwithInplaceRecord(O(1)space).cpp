class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            step2:
            [[0,1,2,0],
             [3,4,5,2],
             [1,3,1,5]]
            step3:
            [[0,1,2,0],
             [3,4,5,0],
             [1,3,1,0]]
        */
        //Step1: Mark if the first row and col has 0:
        bool firstRow = 0, firstCol = 0;
        for(int i=0;i<matrix.size();i++){
            if(matrix[i][0]==0){
                firstCol = 1;
                break;
            }
        }
        for(int j=0;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                firstRow = 1;
                break;
            }
        }        
        //Step2: Iterate the remain elements except first row and col, then mark their first row and col.
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        //Step3: According to step2 marked result to set the corresponding row and col into 0.
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                for(int j=1;j<matrix[0].size();j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=1;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                for(int i=1;i<matrix.size();i++){
                    matrix[i][j] = 0;
                }
            }
        }
        //Step4: Handle the first col and row situation by flag in step1.
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
        
        /*
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<<matrix[i][j]<<",";
            }
        }
        */
    }
};