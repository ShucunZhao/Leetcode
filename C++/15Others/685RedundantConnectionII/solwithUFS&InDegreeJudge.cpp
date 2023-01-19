/*
 * The defference between 684 is there are two situations of this problem:
 * Require1: Each node must have only one parent.
 * Require2: It's a tree which means there is no cycle.
 * Solution:
 * Use an indegree array to represent the in degree of each out node(edges[i][1]).
 * If there is no edges indegree equal to 2, then we just need to find the last edge of the cycle.
 * else we need to skip one of edge whose indegree is 2 and determine if there is no cycle, if so return.
 * If didn't find any meeting edge return empty.
 */
class Solution {
private:
    static const int n = 1005;
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int inDegree[n] = {0};
        int twoIn = -1;
        for(int i=0;i<edges.size();i++){
            inDegree[edges[i][1]]++;
            if(inDegree[edges[i][1]]==2){
                twoIn = edges[i][1];
                break;
            }
        }
        if(twoIn==-1) return deteCycle(edges, {});
        for(int i=edges.size()-1;i>=0;i--){
            if(edges[i][1]==twoIn){
                if(deteCycle(edges, edges[i]).empty()) return edges[i];
            }
        }
        return {};
    }
};