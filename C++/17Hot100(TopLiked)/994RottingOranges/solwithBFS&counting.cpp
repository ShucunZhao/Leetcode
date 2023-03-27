class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // cout<<"m:"<<m<<endl;
        // cout<<"n:"<<n<<endl;
        int fresh = 0;
        queue<pair<int,int> > Q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    Q.push({i,j});
                }
                else if(grid[i][j]==1) fresh++;
            }
        }        
        int cnt = -1;
        int size = 0;
        while(!Q.empty()){
            size = Q.size();
            while(size--){
                int i = Q.front().first;
                int j = Q.front().second;
                Q.pop();
                if(i>0&&grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    fresh--;
                    Q.push({i-1,j});
                }
                if(i<(m-1)&&grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    fresh--;
                    Q.push({i+1, j});
                }
                if(j>0&&grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    fresh--;
                    Q.push({i, j-1});
                }
                if(j<(n-1)&&grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    fresh--;
                    Q.push({i,j+1});
                }
            }
            cnt++;
        }
        if(fresh!=0) return -1;
        if(cnt==-1) return 0;
        // cout<<"cnt:"<<cnt<<endl;
        return cnt;
    }
};