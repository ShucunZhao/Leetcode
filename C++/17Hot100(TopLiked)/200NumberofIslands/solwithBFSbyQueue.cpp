class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
       queue<pair<int,int> > Q;
       int row = grid.size(), col = grid[0].size();
       int ans = 0;
       for(int i=0;i<row;i++){
           for(int j=0;j<col;j++){
               if(grid[i][j]=='1'){
                   ans++;
                   Q.push({i,j});
                   grid[i][j] = '0';
                   while(!Q.empty()){
                       int x = Q.front().first;
                       int y = Q.front().second;
                    //    cout<<"x:"<<x<<","<<"y:"<<y<<endl;
                       Q.pop();
                       if(x-1>=0&&grid[x-1][y]=='1'){
                           Q.push({x-1,y});
                           grid[x-1][y] = '0';
                       }
                       if(x+1<row&&grid[x+1][y]=='1'){
                           Q.push({x+1,y});
                           grid[x+1][y] = '0';
                       }
                       if(y-1>=0&&grid[x][y-1]=='1'){
                           Q.push({x,y-1});
                           grid[x][y-1] = '0';
                       }
                       if(y+1<col&&grid[x][y+1]=='1'){
                           Q.push({x,y+1});
                           grid[x][y+1] = '0';
                       } 
                   }
               }
           }
        }
        return ans;
    }
};