class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool backtracking(int i, int j, int m, int n, vector<vector<char> > & matrix, string word, int start){
        if(i>=m||i<0||j>=n||j<0||matrix[i][j]!=word[start]||matrix[i][j]=='*'){//Edge control and false cases.
            return 0;
        }
        if(start==word.size()-1){//If traverse to the last element of word that means the searching is successful.
            return 1;
        }
        matrix[i][j] = '*';//If current element is acceptable, we mark it into '*' to prevent access repeately in next dfs.
        bool up = backtracking(i-1,j,m,n,matrix,word,start+1);
        bool down = backtracking(i+1,j,m,n,matrix,word,start+1);
        bool left = backtracking(i,j-1,m,n,matrix,word,start+1);
        bool right = backtracking(i,j+1,m,n,matrix,word,start+1);
        matrix[i][j] = word[start];//Backtracking: if the dfs of four directions finish, restore the current char back to original.
        return up||down||left||right;
    }
    bool hasPath(vector<vector<char> >& matrix, string word) {
        // write code here
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(backtracking(i,j,m,n,matrix,word,0)){
                    return true;
                }
            }
        }
        return 0;
    }
};