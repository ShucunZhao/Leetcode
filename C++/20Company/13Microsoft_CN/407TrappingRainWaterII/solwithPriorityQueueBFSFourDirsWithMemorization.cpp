class Solution {
public:
    class myCmp{
    public:
        bool operator()(const vector<int> & A, const vector<int> & B) const{
            return A[2]>B[2];
        }
    };
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        priority_queue<vector<int>, vector<vector<int> >, myCmp> pq;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||j==0||i==m-1||j==n-1){
                    pq.push({i,j,heightMap[i][j]});
                    visited[i][j] = true;
                }
            }
        }
        int minH = INT_MIN;
        int ans = 0;
        vector<vector<int> > dir = {{-1,0},{1,0},{0,-1},{0,1}};
        while(!pq.empty()){
            vector<int> cur = pq.top();
            pq.pop();
            int x = cur[0], y = cur[1];
            int curH = cur[2];
            if(curH>minH){
                minH = curH;
                // continue;
            }
            // else{
            ans+=(minH-curH);
            // }
            //Use bfs to flood expend in four directions:
            // int upX = x-1, upY = y, downX = x+1, downY = y, leftX = x, leftY = y-1, rightX = x, rightY = y+1;
            for(int i=0;i<4;i++){
                int newX = x+dir[i][0], newY = y+dir[i][1];
                if(newX<0||newX>=m||newY<0||newY>=n||visited[newX][newY]){
                    continue;
                }
                pq.push({newX, newY, heightMap[newX][newY]});
                visited[newX][newY] = true;
            }

        }
        
        /*
        cout<<"size:"<<pq.size()<<endl;
        while(!pq.empty()){
            cout<<pq.top()[2]<<",";
            pq.pop();
        }
        cout<<endl;
        */
        return ans;
    }
};
// 15182345792
