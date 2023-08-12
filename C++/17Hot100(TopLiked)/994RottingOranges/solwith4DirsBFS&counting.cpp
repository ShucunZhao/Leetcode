class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;//Count the number of fresh ones.
        queue<pair<int,int> > Q;//Queue to save rotten then use BFS to extend from four directions.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2){
                    Q.push(make_pair(i,j));
                }
            }
        }
        if(fresh==0) return 0;
        // cout<<"fresh:"<<fresh<<endl;
        // dirs[i][0]+x, dirs[i][1]+y
        vector<vector<int> > dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        int ans = 0;
        int size;
        while(!Q.empty()){
            size = Q.size();
            ans++;
            while(size--){
                auto cur = Q.front();
                Q.pop();
                // cout<<"cur.first:"<<cur.first<<",cur.second:"<<cur.second<<endl;
                for(int i=0;i<dirs.size();i++){
                    int newI = cur.first+dirs[i][0];
                    int newJ = cur.second+dirs[i][1];
                    // cout<<"newI:"<<newI<<",newJ:"<<newJ<<endl;//0,1
                    if(newI>=0&&newI<m&&newJ>=0&&newJ<n&&grid[newI][newJ]==1){
                        // cout<<"fresh:"<<fresh<<endl;
                        grid[newI][newJ] = 2;
                        fresh--;
                        if(fresh==0) return ans;
                        Q.push(make_pair(newI,newJ));
                    }
                }
            }
            // cout<<"fresh2:"<<fresh<<endl;
            // cout<<"ans:"<<ans<<endl;
        }
        // cout<<"fresh:"<<fresh<<",ans:"<<ans<<endl;
        if(fresh>0) return -1;
        return ans;
        // return ans==-1?0:ans;
    }
};