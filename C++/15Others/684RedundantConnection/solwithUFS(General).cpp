class Solution {
private:
    int n = 1005;
    int father[1005];
    void init(){
        for(int i=0;i<n;i++){
            father[i] = i;
        }
    }
    int find(int In){
        while(In!=father[In]){
            In = father[In];
        }
        return In;
        // return In == father[In] ? In : father[In] = find(father[In]);
    }
    bool same(int p, int q){
        return find(p)==find(q);
    }
    void Union(int p, int q){
        p = find(p);
        q = find(q);
        if(p==q) return;
        father[q] = p;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init();
        for(int i=0;i<edges.size();i++){
            if(same(edges[i][0],edges[i][1])) return edges[i];
            else{
                Union(edges[i][0],edges[i][1]);
            }
        }
        return {};
    }
};