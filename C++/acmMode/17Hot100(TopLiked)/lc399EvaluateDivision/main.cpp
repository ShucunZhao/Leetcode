#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <list>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void dfs(string src, string dst, double cur, vector<double>& ans, map<string, list<pair<string, double> > >& ms, unordered_set<string> & isVisited, int size) {
        if (ans.size() > size) {
            return;
        }
        if (isVisited.count(src)) return;
        if (src == dst) {
            ans.push_back(cur);
            return;
        }
        isVisited.insert(src);
        for (auto&  x: ms[src]) {
            dfs(x.first, dst, x.second * cur, ans, ms, isVisited, size);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        /*
            Given: a / b = 2.0, b / c = 3.0
            queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? 
            This is a directed graph with weight:
                a  ->  b  ->  c
                  (2)     (3)

            equations = [["a","b"],["b","c"]], values = [2.0,3.0],
            ms: a->b, 2
                b->c, 3
            We cannot use the adjacency matrix to store the graph info, we need to use map instead
        */
        map<string, list<pair<string, double> > > ms;
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            ms[a].push_back({ b,val });
            ms[b].push_back({ a,1/val });
        }
        /*
            queries: [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
        */
        vector<double> ans;
        int size = ans.size();//Check if valid ans, otherwise add -1.0
        for (int i = 0; i < queries.size(); ++i) {
            string head = queries[i][0];
            string tail = queries[i][1];
            if (ms.count(head) == 0 || ms.count(tail) == 0) {
                ans.push_back(-1.0);
                size = ans.size();
                continue;
            }
            /*
                ms:   a: (b,2)
                      b: (c,3)
                      b: (a,0.5)
                      c: (b,0.33)
            */
            unordered_set<string> isVisited;
            int preSize = ans.size();
            dfs(head, tail, 1.0, ans, ms, isVisited, preSize);
            if (ans.size() == size) {
                ans.push_back(-1.0);
            }
            size = ans.size();
        }
        return ans;
    }
};

void constructStrs(vector<vector<string>>& strs, string& In) {
    In = In.substr(2, In.size() - 4);
    size_t pos;
    while ((pos = In.find("],[")) != string::npos) {
        string token1 = In.substr(0, pos);
        In = In.substr(pos + 3);
        stringstream ss(token1);
        string token2;
        vector<string> tmp;
        while (getline(ss, token2, ',')) {
            tmp.push_back(token2);
        }
        strs.push_back(tmp);
    }
    stringstream ss(In);
    string token2;
    vector<string> tmp;
    while (getline(ss, token2, ',')) {
        tmp.push_back(token2);
    }
    strs.push_back(tmp);
}

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the equations:" << endl;
        string E;
        getline(cin, E);
        if (E == "q") break;
        cout << "Enter the values:" << endl;
        string V;
        getline(cin, V);
        if (V == "q") break;
        cout << "Enter the queries :" << endl;
        string Q;
        getline(cin, Q);
        if (Q == "q") break;
        vector<vector<string>> equations;
        vector<vector<string>> queries;
        constructStrs(equations, E);
        V = V.substr(1, V.size() - 2);
        stringstream ss(V);
        string token;
        vector<double> values;
        while (getline(ss, token, ',')) {
            values.push_back(stod(token));
        }
        constructStrs(queries, Q);
        vector<double> res = S1.calcEquation(equations, values, queries);
        cout << "Res: [";
        for (double& d : res) cout << d << ",";
        cout << "]" << endl;
    }
}