class Solution {
public:
    bool backtracking(int rowNum, int colNum, vector<vector<char>>& board){
        for(int i=0;i<rowNum;i++){
            for(int j=0;j<colNum;j++){
                if(board[i][j]=='.'){
                    for(char k='1';k<='9';k++){
                        if(isValid(i,j,k,board)){
                            board[i][j] = k;
                            bool ans = backtracking(rowNum, colNum, board);
                            if(ans){
                                return 1;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return 0;
                }
            }
        }
        return 1;
    }
    bool isValid(int row, int col, char val, vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(board[row][i]==val) return 0;
        }
        for(int j=0;j<9;j++){
            if(board[j][col]==val) return 0;
        }
        int start = (row/3)*3;
        int end = (col/3)*3;
        for(int i=start;i<start+3;i++){
            for(int j= end;j<end+3;j++){
                if(board[i][j]==val) return 0;
            }
        }
        return 1;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int rowNum = board.size();
        int colNum = board[0].size();
        backtracking(rowNum, colNum, board);
    }
};