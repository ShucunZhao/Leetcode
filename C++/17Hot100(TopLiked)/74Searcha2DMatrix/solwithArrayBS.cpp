class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
                        l
             matrix = [[1,  3, 5, 7],
                       [10,11,16,20],
                       [23,30,34,60]],   target = 3
                                  r
        */
        vector<int> arr(matrix.size()*matrix[0].size());
        int index = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                arr[index++] = matrix[i][j];
            }
        }
        int l=0,r=arr.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(arr[m]>target){
                r = m-1;
            }
            else if(arr[m]<target){
                l = m+1;
            }
            else{
                return 1;
            }
        }
        /*
        for(int i : arr){
            cout<<i<<",";
        }
        cout<<endl;
        */
        return 0;
    }
};