class Solution {
public:
    vector<vector<int> > ans;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        path.clear();
        backtracking(n,k,1);
        return ans;
    }
    void backtracking(int n, int k, int start){
        if(path.size()==k){
            ans.push_back(path);
            return;
        }
        for(int i = start;i<=n-(k-path.size())+1;i++){//Here doing the pruning operation:
                                                      //path.size(): Chosen quntity
                                                      //k-path.size(): Still need quantity
                                                      //n-(k-path.size())+1: The most starting position in set n
            path.push_back(i);
            backtracking(n, k, ++start);
            path.pop_back();
        }
        return;
    }
};