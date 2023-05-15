class Solution {
public:
    class UnionFind{
        public:
            vector<int> id;
            vector<int> size;
            UnionFind(int N):id(vector<int>(N,0)),size(vector<int>(N,1)){//Initialization.
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
                if(size[pRoot]>size[qRoot]){
                    size[pRoot]+=size[qRoot];
                    id[qRoot] = id[pRoot];
                }
                else{
                    size[qRoot]+=size[pRoot];
                    id[pRoot] = id[qRoot];
                }
            }
            //Do the path compression step in find() func:
            int find(int In){
                while(In!=id[In]){
                    id[In] = id[id[In]];
                    In = id[In];
                }
                return In;
            }
            /*
            //Or you can write with a recursively way:
            int find(int In){
                if(In!=id[In]){
                    id[In] = find(id[In]);
                }
                return id[In];
            }
            */

    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //vector<int> ans;
        int N = edges.size();
        UnionFind UF(N+1);
        /*
            Why size is N+1 here:
            if you want to use your UnionFind class to solve the problem of finding the redundant connection in a graph,      
            you need to consider that the graph has N nodes, but N-1 edges. This means that there is one node that is not connected to any other node in the graph. Therefore, you need to allocate one more element in your id and size vectors to represent this isolated node. That is why you need to add one to N when you initialize your vectors.
        */
        for(auto x : edges){
            if(UF.isConnected(x[0], x[1])){
                return {x[0], x[1]};
            }
            else{
                UF.Union(x[0], x[1]);
            }
        }
        return {-1, -1};
    }
};