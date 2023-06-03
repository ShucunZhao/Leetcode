class Solution {
public:
    class myCmp{
        public:
            bool operator()(const pair<int,int> & A, const pair<int,int> & B)const{
                return A.second > B.second;
            }
    };
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
            Dijkstra:
            times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
            src: 2
            vector<int> dis(n+1, MAX);
            dis[src] = 0;
            From src to smooth the path:

        */
        vector<vector<long long> >graph(n+1, vector<long long>(n+1, INT_MAX));
        for(int i=0;i<times.size();i++){
            graph[times[i][0]][times[i][1]] = times[i][2];
        }
        int src = k;
        vector<bool> visit(n+1, false);//Record the if visited.
        //priority_queue<pair<int, int>, vector<pair<int,int> >, myCmp> pq;//Record the shortest distance from src to point i, pair<index, dist>.
        /*
        for(int i=1;i<=n;i++){
            if(i==src){
                pq.push(make_pair(i,0));
                continue;
            }    
            pq.push(make_pair(i,INT_MAX));
        }
        graph[src][src] = 0;
        */
        /*
            2-2: 0
            src = 2
            graph[2][1], graph[2][2], graph[2][3], graph[2][4] ... graph[2][k]
            graph[src][1] ... graph[k]
        */
        //while(!pq.empty()){
        while(1){
            int minI = 0;
            int minDist = INT_MAX;
            //int tmp = pq.top().first;
            for(int i=1;i<=n;i++){
                if(!visit[i]&&graph[src][i]<minDist){
                    minI = i;
                    minDist = graph[src][i];
                }
            }
            if(minI==0) break;//End loop condition.
            if(!visit[minI]){
                visit[minI] = true;
                for(int i=1;i<=n;i++){
                    if(!visit[i]){
                        graph[src][i] = min(graph[src][i], graph[src][minI]+graph[minI][i]);
                        //pq.push({i, graph[src][i]});
                    }
                }
            }
            //pq.pop();
        }
        /*
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<graph[i][j]<<",";
                // cout<<"graph["<<i<<"]"<<"["<<j<<"]:"<<graph[i][j]<<endl;
            }
            cout<<endl;
        }
        */
        /*
        while(!pq.empty()){
            cout<<"i:"<<pq.top().first<<",dis:"<<pq.top().second<<endl;
            pq.pop();
        }
        */
        long long ans = -1;
        for(int i=1;i<=n;i++){
            if(k==i){
                continue;
            }
            if(graph[k][i]==INT_MAX) return -1;
            ans = max(ans, graph[k][i]);
        }
        return ans;
    }
};