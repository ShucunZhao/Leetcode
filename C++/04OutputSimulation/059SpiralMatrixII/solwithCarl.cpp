class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int cnt=1;
        int i=0,j=0;
        int check = n/2;
        int size = n;        
        while(check>0){//The times to write the board,
                       //which is depended on the given n.
            for(i,j;j<n-1;j++){//Board1: i=0,j=0
                ans[i][j] = cnt++;
                //cnt++;
            }
            for(i,j;i<n-1;i++){//Board2: i=0,j=n-1
                ans[i][j] = cnt++;
                //cnt++;
            }
            for(i,j;j>size-n;j--){//Board3: i=n-1;j=n-1
                ans[i][j] = cnt++;
                //cnt++;
            }
            for(i,j;i>size-n;i--){//Board4: i=n-1,j=0
                ans[i][j] = cnt++;
                //cnt++;
            }
            //Increase all the inital position by one when finish each board writing.
            i++;
            j++;
            n--;//Reduce the ending position at the same time.
            check--;
        }
		//At last: If given n is odd you need write the last center element with cnt
		//else just return ans.
        if(size%2==1){
            ans[size/2][size/2] = cnt;
        }
        return ans;
    }
};