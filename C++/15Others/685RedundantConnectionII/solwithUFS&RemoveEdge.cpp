class Solution {
public:
    class UnionFind{
    public:
        vector<int> id;
        vector<int> sz;
        UnionFind(int N):id(vector<int>(N,0)),sz(vector<int>(N, 1)){
            for(int i=0;i<N;i++){
                id[i] = i;
            }
        }
        bool isConnected(int p, int q){
            return find(p)==find(q);
        }
        void Union(int p, int q){
            int pRoot = find(p);
            int qRoot = find(q);
            if(pRoot==qRoot) return;
            if(sz[pRoot]>sz[qRoot]){
                sz[pRoot]+=sz[qRoot];
                id[qRoot] = id[pRoot];
            }
            else{
                sz[qRoot]+=sz[pRoot];
                id[pRoot] = id[qRoot];
            }
        }
        int find(int x){
            while(x!=id[x]){
                id[x] = id[id[x]];
                x = id[x];
            }
            return x;
        }
    };
    vector<int> detectCycle(vector<vector<int>>& edges, vector<int> skip){
        int n = edges.size();
        UnionFind uf(n+1);
        for(auto edge : edges){
            if(edge[0]==skip[0]&&edge[1]==skip[1]){
                continue;
            }
            if(uf.isConnected(edge[0], edge[1])){
                return {edge[0], edge[1]};
            }
            else{
                uf.Union(edge[0], edge[1]);
            }
        }
        return {-1,-1};
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        /*First step to count the indegree*/
        map<int, vector<vector<int> > > ms;
        for(int i=0;i<edges.size();i++){
            ms[edges[i][1]].push_back({edges[i][0], edges[i][1]});
        }
        vector<vector<int> > skipSet; 
        for(auto x : ms){
            if(x.second.size()>1){
                for(auto vec : x.second){
                    skipSet.push_back({vec[0], vec[1]});
                    // cout<<vec[0]<<","<<vec[1]<<endl;
                }
            }
        }
        cout<<skipSet.size()<<endl;
        /*Second step: Find cycle edge and the overlap of indegree is larger than one answer:*/
        if(!skipSet.empty()){
            for(int i=skipSet.size()-1;i>=0;i--){//KeyPoint: We need to traverse with a reverse order to get the last answer.
                vector<int> res = detectCycle(edges, skipSet[i]);
                if(res[0]==-1){
                    return skipSet[i];
                }
            }
        }
        return detectCycle(edges, {-1,-1});
    }
};