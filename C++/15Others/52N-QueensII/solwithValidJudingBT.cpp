class Solution {
public:
    int ans = 0;
    bool isValid(vector<vector<bool> > & chessboard, int n, int row, int col){
        for(int i=0;i<row;i++){
            if(chessboard[i][col]==1) return 0;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(chessboard[i][j]==1) return 0;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(chessboard[i][j]==1) return 0;
        }
        return 1;
    }
    void backtracking(vector<vector<bool> > & chessboard, int n, int row){
        if(row==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(chessboard, n, row, i)){
                chessboard[row][i] = 1;
                backtracking(chessboard, n, row+1);
                chessboard[row][i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<bool> > chessboard(n, vector<bool>(n, 0));
        backtracking(chessboard, n, 0);
        return ans;
    }
};