class Solution {
public:
    unordered_map<string, int> ms;
    int dfs(string s){
        if(ms.count(s)) return ms[s];
        if(s.empty()) return 1;
        if(s[0]=='0') return 0;
        if(s.size()==1){
            return 1;
        }
        int case1 = dfs(s.substr(1));
        int case2 = 0;
        // if(s.size()>1){
        string tmp = s.substr(0, 2);
        if(stoi(tmp)<=26){
            case2+=dfs(s.substr(2));
        }
        ms[s] = case1+case2;
        return ms[s];
    }

    int numDecodings(string s) {
        /*
            "11106"
        */
        return dfs(s);
    }
};
