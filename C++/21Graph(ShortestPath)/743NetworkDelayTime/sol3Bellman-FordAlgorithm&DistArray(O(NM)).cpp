class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
            Bellman-ford:
            times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
            src: 2
            vector<int> dis(n+1, MAX);
            dis[src] = 0;
            From src to smooth all the edges until no update:
        */
        /*
        //Step1: Save info in graph.
        vector<vector<long long> > graph(n+1, vector<long long>(n+1, INT_MAX));
        for(int i=0;i<times.size();i++){
            graph[times[i][0]][times[i][1]] = times[i][2];
        }
        */
        //Step2: initial all distance from source to current be MAX, and set the dist from source to source be 0.
        vector<long long> dist(n+1, INT_MAX);
        dist[k] = 0;
        //Step3: Smooth all the edges by dist array until no update.
        /*
            max(dist[end], dist[tmp]+dist[end])
        */
        while(1){
            bool update = false;
            for(int i=0;i<times.size();i++){
                int tmp = times[i][0];
                int end = times[i][1];
                if(dist[end]>dist[tmp]+times[i][2]){
                    update = true;
                    dist[end] = dist[tmp]+times[i][2];
                }
            }
            if(!update){
                break;
            }
        }
        long long ans = -1;
        for(int i=1;i<=n;i++){
            if(i==k){
                continue;
            }
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans, dist[i]);
            //cout<<dist[i]<<endl;
        }
        return ans;
    }
};