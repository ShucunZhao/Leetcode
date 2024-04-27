#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class Solution {
public:
    map<vector<int>, int> ms;
    int numDistinct(string s, string t) {
        /*
            Input: s = "rabbbit", t = "rabbit"
                        i
                    s = rabbbit
                    t = rabbit
                        j
        */
        return dfs(s, t, 0, 0);
    }
    int dfs(string & s, string & t, int i, int j) {
        if (j == t.size()) return 1;
        if (i == s.size()) return 0;
        vector<int> Pair = { i, j };
        if (ms.count(Pair)) return ms[Pair];
        if (s[i] == t[j]) {
            ms[Pair] = dfs(s, t, i + 1, j + 1) + dfs(s, t, i + 1, j);
            return ms[Pair];
        }
        else {
            ms[Pair] = dfs(s, t, i + 1, j);
            return ms[Pair];
        }
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the s:" << endl;
        string s;
        getline(cin, s);
        if (s == "q") break;
        cout << "Enter the t:" << endl;
        string t;
        getline(cin, t);
        if (t == "q") break;
        s = s.substr(1, s.size() - 2);
        t = t.substr(1, t.size() - 2);
        cout << "Res: " << S1.numDistinct(s, t) << endl;
    }
}