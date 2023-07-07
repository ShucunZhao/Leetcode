class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
                      l
                      0   1   2   3
                     0,0 0,1 0,2 0,3
            matrix =  [1, 3, 5,  7]
                      4   5   6   7 
                     1,0 1,1 1,2 1,3
                      [10,11,16, 20]
                      8   9  10  11
                     2,0 2,1 2,2 2,3           
                      [23,30,34, 60]
                                 r 

            index = row*n + col;
            index/n = row, index%n =                     

        */
        //m: 3              n:4
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m*n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int row = mid/n;
            int col = mid%n;
            if(matrix[row][col]>target){
                r = mid-1;
            }
            else if(matrix[row][col]<target){
                l = mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};