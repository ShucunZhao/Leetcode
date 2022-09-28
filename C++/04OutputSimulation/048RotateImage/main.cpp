/*
 * You need to divide the rotate 90 degree task into two step:
 * Step 1. Exchange the element with main diagonal(From northwest corner to southeast corner). 
 * Step 2. Exchange the element with middle vertical line of symmetry. 
 */
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        //Step 1:
        for(int i=0;i<rows;i++){
            for(int j=i;j<cols;j++){//Key point here: you also need to increse the column by one 
                                    //when you change the new row.
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //Step2:
        for(int k=0;k<rows;k++){
            for(int l=0;l<cols/2;l++){
                swap(matrix[k][l], matrix[k][cols-l-1]);//Key point here: you also need to shrink the column index
                                                        //when you exchange the element with the middle vertical line.
            }
        }
    }
};