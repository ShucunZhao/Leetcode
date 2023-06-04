class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        /*
            Upgraded version of Bellman-ford which is called SPFA:
            Use the queue to accelerate the smooth operation. 
            times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
            src: 2
            vector<int> dis(n+1, MAX);
            dis[src] = 0;
            From src to smooth all the edges until no update:
        */
        //Step1: initial all distance from source to current be MAX, and set the dist from source to source be 0.
        vector<long long> dist(n+1, INT_MAX);
        dist[k] = 0;
        //Step2: Smooth all the edges by dist array until no update and use queue to avoid not neccessary loop.
        /*
            max(dist[end], dist[tmp]+dist[end])
        */
        queue<long long> Q;//If the adjacent node can be updated, add them into queue.
        vector<bool> check(n+1, false);//This array is used for checking if the head element is exist in queue.
        Q.push(k);//Add the source node into queue at first.
        check[k] = true;
        //while(1){//If there are negative cirle we need to use for-loop from 1 to N-1 instead 
                //and judge one more time after two loop to determine there are negative circle.
        while(!Q.empty()){
            //bool update = false;
            int src = Q.front();
            Q.pop();
            check[src] = false;
            for(int i=0;i<times.size();i++){
                int tmp = times[i][0];
                if(tmp==src){
                    int end = times[i][1];
                    if(dist[end]>dist[tmp]+times[i][2]){
                        //update = true;
                        dist[end] = dist[tmp]+times[i][2];
                        if(!check[end]){
                            Q.push(end);
                        } 
                    }
                }
            }
            //if(!update){
            //    break;
            //}
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