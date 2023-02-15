class Solution {
public:
    bool backtracking(int start, int row, int col, vector<vector<char>>& board, string & word, vector<vector<bool>>& used){
        if(start==word.size()){
            return 1;
        }
        if(row<0||col<0||row==board.size()||col==board[0].size()||used[row][col]||board[row][col]!=word[start]){    
            return 0;
        }
        // cout<<board[row][col]<<","<<start<<endl;
        used[row][col] = 1;
        bool rst = backtracking(start+1, row-1, col, board, word, used)||backtracking(start+1, row, col-1, board, word, used)||backtracking(start+1, row+1, col, board, word, used)||backtracking(start+1, row, col+1, board, word, used);
        used[row][col] = 0;
        return rst;
    }
    bool exist(vector<vector<char>>& board, string word) {
        /*
             board = [["A","B","C","E"],
                      ["S","F","C","S"],
                      ["A","D","E","E"]], 
            word   =  "ABCCED"
                        A
                S-AS(X)    B-AB 
                 F-ABF(X)   |   C-ABC
                           C-ABCC  |  E-ABCE(X)
            F-ABCCF(X)  |  E-ABCCE |   S-ABCCS(X)
                E-ABCCEE(X)   |   D-ABCCED(o)            
        */
        vector<vector<bool> > used(board.size(), vector<bool>(board[0].size(), 0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtracking(0, i, j, board, word, used)){
                    return 1;
                }
            }
        }
        return 0;
    }
};