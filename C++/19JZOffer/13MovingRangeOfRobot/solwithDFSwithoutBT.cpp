class Solution {
public:
    int getDigitSum(int In){
        //cout<<"Get digit"<<In<<":"<<endl;
        int ans = 0;
        while(In){
            ans+=(In%10);
            In/=10;
        }
        //cout<<ans<<endl;
        return ans;
    }
    int dfs(int i, int j, int rows, int cols, int T, vector<vector<bool> > & check){
        if(i>=rows||j>=cols||(getDigitSum(i)+getDigitSum(j))>T||check[i][j]){
            return 0;
        }
        check[i][j] = 1;
        int right = dfs(i,j+1,rows,cols,T,check);
        int down = dfs(i+1,j,rows,cols,T,check);
        //check[i][j] = 1;//KeyPoint here: we shouldn't do the backtracking step here beacause the whole map should be marked if they were accessed once!
        return right+down+1;
    }
    int movingCount(int threshold, int rows, int cols) {
        /*   t: 1, rows: 2, cols: 3
           j:
          i:   x x x
               x x x    
        */
        vector<vector<bool> > check(rows, vector<bool>(cols, 0));
        return dfs(0,0,rows,cols,threshold,check);
    }
};