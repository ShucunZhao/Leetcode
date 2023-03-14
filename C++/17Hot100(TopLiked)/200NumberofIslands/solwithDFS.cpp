class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j, int row, int col){
        if(i<0||j<0||i>row||j>col||grid[i][j]=='0') return;
        grid[i][j] = '0';
        // cout<<"i:"<<i<<","<<"j:"<<j<<endl;
        dfs(grid, i+1, j, row, col);
        dfs(grid, i-1, j, row, col);
        dfs(grid, i, j+1, row, col);
        dfs(grid, i, j-1, row, col);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size()-1;
        int col = grid[0].size()-1;
        int ans = 0;
        for(int i=0;i<=row;i++){
            for(int j=0;j<=col;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid, i, j, row, col);
                }
            }
        }
        return ans;
    }
};