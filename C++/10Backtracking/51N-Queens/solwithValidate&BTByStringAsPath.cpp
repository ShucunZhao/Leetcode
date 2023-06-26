class Solution {
public:
    vector<vector<string> > ans;
    /*
        Pay attention to the N queen rule!!!
        It should consider the row and col and the diagonal 
    */
    bool isValid(int row, int col, vector<string> & chessboard, int n){
        for(int i=0;i<row;i++){
            if(chessboard[i][col]=='Q'){
                return false;
            }
        }

        for(int i=row-1, j=col-1;i>=0&&j>=0;i--,j--){
            if(chessboard[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(chessboard[i][j]=='Q') return false;
        }
        return true;
    }

    void backtracking(vector<string> & chessboard, int n, int start){
        if(start==n){
            ans.push_back(chessboard);
            return;
        }
        for(int col=0;col<n;col++){
            if(isValid(start, col, chessboard, n)){
                chessboard[start][col] = 'Q';
                backtracking(chessboard, n, start+1);
                chessboard[start][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtracking(chessboard, n, 0);
        return ans;
    }
};