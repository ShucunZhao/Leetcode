class Solution {
public:
    int findIndex(vector<int> & array, int target, int l, int r){
        while(l<=r){
            int m = l+(r-l)/2;
            if(array[m]>target){
                r = m-1;
            }
            else if(array[m]<target){
                l = m+1;
            }
            else{
                return m;
            }
        }
        return -1;
    }
    bool Find(int target, vector<vector<int> > array) {
        /*
             target = 7,  target = 3
            [
             l
            [1,2,8,9],
            [2,4,9,12],
            [4,7,10,13],
            [6,8,11,15]
            ]
        */
        int m = array.size(), n = array[0].size();
        for(int i=0;i<m;i++){
            if(findIndex(array[i], target, 0, n-1)!=-1){
                return 1;
            }
        }
        return 0;
    }
};



