class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> mset;
        //Traverse each rows:
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(mset.count(board[i][j])){
                        return false;
                    }
                    mset.insert(board[i][j]);
                }
            }
            mset.clear();
        }
        mset.clear();
        //Traverse each cols:
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[j][i]!='.'){
                    if(mset.count(board[j][i])){
                        return false;
                    }
                    mset.insert(board[j][i]);
                }
            }
            mset.clear();
        }
        mset.clear();
        /*
        r+=3 within r<9
            r c
            0,0
            from r to r+3
                form c to c+3
            c+=3 within c<9
        */
        /*
        for(int row=0;row<9;row+=3){
            for(int col=0;col<9;col+=3){
                for(int i=row;i<row+3;i++){
                    for(int j=col;j<col+3;j++){
                        if(board[i][j]!='.'){
                            if(mset.count(board[i][j])){
                                return false;
                            }
                            mset.insert(board[i][j]);
                        }
                    }
                }
                mset.clear();
            }
        }
        */
        for(int block=0;block<9;block++){
            int row = (block/3)*3;//0,0
            int col = (block%3)*3;//0,3
            for(int i=row;i<row+3;i++){
                for(int j=col;j<col+3;j++){
                    if(board[i][j]!='.'){
                        if(mset.count(board[i][j])){
                            return false;
                        }
                        mset.insert(board[i][j]);
                    }
                }
            }
            mset.clear();
        }
        return true;
    }
};