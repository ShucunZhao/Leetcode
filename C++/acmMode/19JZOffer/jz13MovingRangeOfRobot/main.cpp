class Solution {
public:
    int movingCount(int threshold, int rows, int cols) {
       vector<vector<bool> > isVisited(rows, vector<bool>(cols,false));
       return backtracking(0,0,rows,cols,isVisited,threshold);
    }
    int getNumber(int row, int col){
        int num = 0;
        while(row){
            num+=(row%10);
            row/=10;
        }
        while(col){
            num+=(col%10);
            col/=10;
        }
        return num;
    }
    int backtracking(int row, int col, int rows, int cols, vector<vector<bool> > & isVisited, int threshold){
        if(row<0||row>=rows||col<0||col>=cols||isVisited[row][col]||getNumber(row,col)>threshold){
            return 0;
        }
        isVisited[row][col] = true;
        return 1+backtracking(row-1,col,rows,cols,isVisited,threshold)+backtracking(row+1,col,rows,cols,isVisited,threshold)+backtracking(row,col-1,rows,cols,isVisited,threshold)+backtracking(row,col+1,rows,cols,isVisited,threshold);
    }
};