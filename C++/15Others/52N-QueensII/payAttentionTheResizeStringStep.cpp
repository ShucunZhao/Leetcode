class Solution {
public:
    vector<string> chessboard;
    vector<vector<string> > ans;
    bool isValid(int row, int col, int n){
        for(int i=0;i<row;i++){
            if(chessboard[i][col]=='Q') return 0;
        }
        /*
        //You don't need this step because each row only put one queen.
        for(int j=0;j<col;j++){
            if(chessboard[row][j]=='Q') return 0;
        }
        */
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(chessboard[i][j]=='Q') return 0;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(chessboard[i][j]=='Q') return 0;
        }
        return 1;
    }
    void backtracking(int start, int n){
        if(start==n){
            ans.push_back(chessboard);
        }
        for(int i=0;i<n;i++){
            if(!isValid(start, i, n)){
                continue;
            }
            chessboard[start][i] = 'Q';
            backtracking(start+1, n);
            chessboard[start][i] = '.';
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        chessboard.resize(n, string(n, '.'));
        backtracking(0, n);
        return ans;
    }
};