class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
            m = 3, n = 4
                         l
                         0   1   2   3
             matrix = 0 [[1, 3,  5,  7],
                      1 [10, 11, 16, 20],
                      2 [23, 30, 34, 60]],   target = 3
                                  r
                index: matrix[mid/n][mid%n]                  
                       0                            11
            arr:       1,3,5,7,10,11,16,20,23,30,34,60,                      
        */
        int m = matrix.size(), n = matrix[0].size();
        int l=0, r=m*n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[mid/n][mid%n]>target){
                r = mid-1;
            }
            else if(matrix[mid/n][mid%n]<target){
                l = mid+1;
            }
            else{
                return 1;
            }
        }
        

        
        return 0;
    }
};