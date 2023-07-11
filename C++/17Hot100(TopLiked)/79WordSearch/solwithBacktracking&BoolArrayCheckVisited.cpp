class Solution {
public:
    //unordered_set<string> mset;
    bool backtracking(int row, int col, int m, int n, int start, vector<vector<char>>& board, string & word, vector<vector<bool> > & visited){
        if(start==word.size()){
            return true;
        }
        if(row<0||col<0||row>=m||col>=n||board[row][col]!=word[start]){
            return false;
        }
        if(visited[row][col]){
            return false;
        }
        // string pos = to_string(row)+","+to_string(col);
        // pos.push_back(row-'0');
        // pos.push_back(col-'0');
        // if(mset.count(pos)){
        //     return false;
        // }
        // char r = row-'0';
        // char c = col-'0';
        // mset.insert(pos);
        visited[row][col] = true;
        bool up = backtracking(row-1, col, m, n, start+1, board, word, visited);
        bool down = backtracking(row+1, col, m, n, start+1, board, word, visited);
        bool left = backtracking(row, col-1, m, n, start+1, board, word, visited);
        bool right = backtracking(row, col+1, m, n, start+1, board, word, visited);
        // mset.erase(pos);
        visited[row][col] = false;
        return up||down||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        /*
 "AAAAAAAAAAAAABB"
             ["A","A","A","A","A","A"]
             ["A","A","A","A","A","A"]
             ["A","A","A","A","A","A"] 
             ["A","A","A","A","A","A"] 
             ["A","A","A","A","A","B"] 
             ["A","A","A","A","B","A"]

            board =  ["C","A","A"]
                     ["A","A","A"]
                     ["B","C","D"]
            word =   "AAB"

            four directions: up down left right
            unordere_set: record the pos(i,j) we visited.

        */  
        int m = board.size(), n = board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(backtracking(i,j,m,n,0,board,word,visited)){
                   return true; 
                }
            }
        }
        return false; 
    }
};