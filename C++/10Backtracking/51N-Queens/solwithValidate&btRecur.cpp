class Solution {
public:
    vector<string> path;
    vector<vector<string> > ans;
    void backtracking(int row, int col){
        if(row==col){
            ans.push_back(path);
            return;
        }
        for(int i=0;i<col;i++){
            if(!isValid(row, i, col)){
                continue;
            }
            path[row][i] = 'Q';
            backtracking(row+1,col);
            path[row][i] = '.';
        }
        return;
    }
    bool isValid(int row, int col, int size){
        for(int i=0;i<row;i++){
            if(path[i][col]=='Q'){
                return 0;
            }
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(path[i][j]=='Q'){
                return 0;
            }
        }
        for(int i = row-1,j=col+1;i>=0&&j<size;i--,j++){
            if(path[i][j]=='Q'){
                return 0;
            }
        }
        return 1;
    }
    vector<vector<string>> solveNQueens(int n) {
        path.resize(n, string(n, '.'));
        int col = n;
        backtracking(0, col);
        return ans;
    }
};