class Solution {
public:
    bool isIsland(int row, int col, int m, int n, vector<vector<char>>& grid){
        if(row<0||col<0||row>=m||col>=n||grid[row][col]=='0'){
            return false;
        }
        grid[row][col] = '0';
        bool up = isIsland(row-1, col, m, n, grid);
        bool down = isIsland(row+1, col, m, n, grid);
        bool left = isIsland(row, col-1, m, n, grid);
        bool right = isIsland(row, col+1, m, n, grid);
        if(up&&down&&left&&right){
            return true;
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        // cout<<"isIsland1:"<<isIsland(0,0,m,n,grid)<<endl;
        // cout<<"isIsland2:"<<isIsland(2,2,m,n,grid)<<endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                // cout<<grid[i][j]<<",";
                if(isIsland(i,j,m,n,grid)){
                    ans++;
                }
            }
            // cout<<endl;
        }
        return ans;
    }
};