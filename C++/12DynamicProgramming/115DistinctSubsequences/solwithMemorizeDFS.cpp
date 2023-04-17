class Solution {
public:
    int dfs(int i, int j, string & s, string & t, map<pair<int,int>, int> & ms){
        if(j==t.size()){
            return 1;
        }
        if(i==s.size()){
            return 0;
        }
        if(ms.count({i,j})){
            return ms[{i,j}];
        }
        if(s[i]==t[j]){
            ms[{i,j}] = dfs(i+1,j+1,s,t,ms)+dfs(i+1,j,s,t,ms);
        }
        else{
            ms[{i,j}] = dfs(i+1,j,s,t,ms);
        }
        return ms[{i,j}];
    }
    int numDistinct(string s, string t) {
        /*
                 t: r a b b i t
             s:  r
                 a
                 b
                 b
                 b
                 i
                 t
        */
        map<pair<int,int>, int> ms;
        return dfs(0,0,s,t,ms);
    }
};