class Solution {
public:
    int start = 0;
    bool isValid(char In, vector<vector<char> > & board, int row, int col){
        //row
        for(int i=0;i<board.size();i++){
            if(board[i][col]==In) return false;
        }
        //col
        for(int j=0;j<board[0].size();j++){
            if(board[row][j]==In) return false;
        }
        //block
        int rowStart = (row/3)*3;
        int colStart = (col/3)*3;
        for(int i=rowStart;i<rowStart+3;i++){
            for(int j=colStart;j<colStart+3;j++){
                if(board[i][j]==In) return false;
            }
        }
        return true;
    }
    bool backtracking(vector<vector<char> > & board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isValid(c, board, i, j)){
                            board[i][j] = c;
                            bool finish = backtracking(board);
                            if(finish) return true;
                        }
                    }
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
        return;
    }
};