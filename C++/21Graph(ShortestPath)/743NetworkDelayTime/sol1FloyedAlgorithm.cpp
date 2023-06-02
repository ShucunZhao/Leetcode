class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
            Floyed:
            times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
            graph:
                   1 2 3 4   
                1 
                2  1   1 2 
                3        1   
                4
          
        */
        vector<vector<long long> > graph(n+1, vector<long long>(n+1, INT_MAX));
        for(int i=0;i<times.size();i++){
            int u = times[i][0], v = times[i][1], w = times[i][2];
            graph[u][v] = w;
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(graph[i][j]>graph[i][k]+graph[k][j]){
                        graph[i][j] = graph[i][k]+graph[k][j];
                    }
                }
            }
        }
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<graph[i][j]<<",";
            }
            cout<<endl;
        }
        */
        long long ans = -1;
        for(int j=1;j<=n;j++){
            if(j==k){
                continue;
            }
            if(graph[k][j]==INT_MAX){
                return -1;
            }
            ans = max(ans, graph[k][j]); 
        }
        return ans;
    }
};