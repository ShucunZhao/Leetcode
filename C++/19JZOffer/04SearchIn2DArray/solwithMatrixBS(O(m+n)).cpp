class Solution {
  public:
    bool Find(int target, vector<vector<int> > array) {
        /*
            [[1,2,8,9],
            [2,4,9,12],
            [4,7,10,13],
            [6,8,11,15]]
        */
        int m = array.size(), n = array[0].size();
        int row = m-1;//1
        int col = 0;
        while(col<=n-1&&row>=0){
            if(array[row][col]>target){
                row--;
            }
            else if(array[row][col]<target){
                col++;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};



