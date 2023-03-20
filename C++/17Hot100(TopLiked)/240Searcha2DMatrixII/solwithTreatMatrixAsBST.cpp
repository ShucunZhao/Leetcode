class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
             matrix = [[1, 4 ,7, 11,15],
                       [2, 5, 8, 12,19],
                       [3, 6, 9, 16,22],
                       [10,13,14,17,24],
                       [18,21,23,26,30]]
            It's a binary search tree from the right up corner:
            so start from the root of BST in "15":
            if larger than target move to left children node from right to 
            left in row;
            if smaller than target move to right children node form top to bottom
            then find the ans. 
        */
        int row = matrix.size(), col = matrix[0].size();
        for(int i=0,j=col-1;i<row&&j>=0;){
            if(matrix[i][j]>target){
                j--;
            }
            else if(matrix[i][j]<target){
                i++;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};