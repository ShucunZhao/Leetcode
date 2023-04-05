class Solution {
public:
    void dfs(string head, string tail, double cur, multimap<string, pair<string, double> > & graph, vector<double> & ans, int index, unordered_set<string> & visited){
        //["a","c"]
        if(visited.count(head)!=0){
            return;
        }
        if(head==tail){
            ans[index] = cur;
            return;
        }
        visited.insert(head);//a,
        /*Another written way:
        auto range = graph.equal_range(head);
        for(auto it = range.first; it != range.second; ++it){
            cout<<it->first<<endl;
            dfs(it->second.first, tail, cur*(it->second.second), graph, ans, index, visited);
        }
        */
        for(auto gra : graph){
            if(gra.first==head){
                dfs(gra.second.first, tail, cur*(gra.second.second), graph, ans, index, visited);
            }
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        multimap<string, pair<string, double> > graph;
        for(int i=0;i<equations.size();i++){
            string numer = equations[i][0];
            string deno = equations[i][1];
            double res = values[i];
            //graph.insert(make_pair(numer, make_pair(deno, res)));
            //graph.insert(make_pair(deno, make_pair(numer, 1.0/res)));
            graph.insert({numer, {deno, res}});
            graph.insert({deno, {numer, 1.0/res}});
        }
        /*
        for(auto gra : graph){
            cout<<gra.first<<"->"<<gra.second.first<<":"<<gra.second.second<<endl;
        }
        cout<<graph.size()<<endl;
        */
        vector<double> ans(queries.size(), -1.0);
        for(int i=0;i<queries.size();i++){
            if(graph.count(queries[i][0])==0||graph.count(queries[i][1])==0){
                continue;
            }
            unordered_set<string> visited;
            dfs(queries[i][0], queries[i][1], 1.0, graph, ans, i, visited);//["a","c"]
        }
        return ans;
    }
};