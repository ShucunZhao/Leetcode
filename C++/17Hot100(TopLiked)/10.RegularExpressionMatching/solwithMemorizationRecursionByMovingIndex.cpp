class Solution {
public:
    map<pair<string, string>, bool> ms;
    bool isMatch(string s, string p) {
        if(ms.count({s,p})){
            return ms[{s,p}];
        }
        if(p.empty()) return s.empty();
        bool first = !s.empty()&&(s[0]==p[0]||p[0]=='.');
        if(p.size()>=2&&p[1]=='*'){
            if(isMatch(s, p.substr(2, p.size()-2))){
                ms[{s,p}] = true;
                return ms[{s,p}];
            }
            if(first){
                ms[{s,p}] = isMatch(s.substr(1, s.size()-1), p);
                return ms[{s,p}];
            }
            ms[{s,p}] = false;
            return ms[{s,p}];
        }
        return first&&isMatch(s.substr(1,s.size()-1), p.substr(1,p.size()-1));
    }
};