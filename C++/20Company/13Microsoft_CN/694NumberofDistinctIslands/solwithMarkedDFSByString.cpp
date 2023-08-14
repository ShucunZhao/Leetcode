class Solution {
public:
    /**
     * @param grid: a list of lists of integers
     * @return: return an integer, denote the number of distinct islands
     */
    unordered_set<string> mset;
    string path;
    bool dfs(int row, int col, int m, int n, vector<vector<int> > & grid, vector<vector<bool> > & visited, string mark){
        if(row<0||row>=m||col<0||col>=n||grid[row][col]==0){
            return false;
        }
		if(visited[row][col]){
			return false;
		}	
        visited[row][col] = true;
        path+=mark;
        bool up = dfs(row-1, col, m, n, grid, visited, "u");
        bool down = dfs(row+1, col, m, n, grid, visited, "d");
        bool left = dfs(row, col-1, m, n, grid, visited, "l");
        bool right = dfs(row, col+1, m, n, grid, visited, "r");   
        if(up||down||left||right){
            return true;
        }   
        // else{
        //     mset.insert(path);
        //     path.clear();
        //     return false;
        // }
        path+="e";
        return false;
    }
    int numberofDistinctIslands(vector<vector<int>> &grid) {
        // write your code here
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]){
                    continue;
                }
                if(!dfs(i,j,m,n,grid,visited, "s")){
					if(!path.empty()){
                    	mset.insert(path);
                    	path.clear();
					}
                }
            }
        }
        return mset.size();
    }
};