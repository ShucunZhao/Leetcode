class Solution {
private:
    int n = 1005;
    int father[1005];
    int size[1005];
    void init(){
        for(int i=0;i<n;i++){
            father[i] = i;
            size[i] = 1;
        }
    }
    int find(int In){
        while(In!=father[In]){
            In = father[In];
        }
        return In;
    }
    // bool isSame(int p, int q){
    //     return find(p)==find(q);
    // }
    bool Union(int p, int q){
        int fp = find(p);
        int fq = find(q);
        if(fp==fq) return false;
        if(size[fp]<size[fq]){
            father[fp] = fq;
            size[fq] += size[fp];
        }
        else{
            father[fq] = fp;
            size[fp] += size[fq];
        }
        return true;
    }
    vector<int> deteCycle(vector<vector<int>>& edges, vector<int> skipEdge){
        init();
        for(int i=0;i<edges.size();i++){
            if(edges[i]==skipEdge) continue; 
            else if(!Union(edges[i][0], edges[i][1])) return edges[i];
        }
        return {};
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        return deteCycle(edges, {});
    }
};