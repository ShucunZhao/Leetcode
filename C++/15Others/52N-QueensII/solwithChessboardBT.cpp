class Solution {
public:
    int ans = 0;
    bool isValid(int row, int col, vector<vector<char> > & chessboard, int n){
        for(int i=0;i<row;i++){
            if(chessboard[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(chessboard[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(chessboard[i][j]=='Q') return false;
        }
        return true;
    }
    void backtracking(int row, vector<vector<char> > & chessboard, int n){
        if(row==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(row, i, chessboard, n)){
                chessboard[row][i] = 'Q';
                backtracking(row+1, chessboard, n);
                chessboard[row][i] = '.';
            }
        }
        return;
    }
    int totalNQueens(int n) {
        vector<vector<char> >chessboard(n, vector<char>(n, '.'));
        backtracking(0, chessboard, n);
        return ans;
    }
};