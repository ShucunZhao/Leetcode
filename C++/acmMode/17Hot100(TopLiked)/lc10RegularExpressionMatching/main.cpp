#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    map<pair<string, string>, bool> ms;
    bool isMatch(string s, string p) {
        /*
        *                i  
            Input: s = "ab", p = ".*"   Output: true
                                   j
            '.' Matches any single character.​​​​
            '*' Matches zero or more of the preceding element.
            s:a
            p:a*
            We can remove element from s or p to mock the matching process:
            Return case:
                if(s.empty()){
                    if(p.size()>=2&&p[1]=='*') return p.substr(2).empty();
                }
                if(p.empty()) return s.empty();
            Case1: general match first element:
                bool first = s[0]==p[0]||p[0]=='.'
            Case2:
                if(p.size()>=2&&p[1]=='*'){
                    Case2.1:
                        if(first){
                            return isMatch(s.substr(1), p);
                        }
                        else{
                            return isMatch(s, p.substr(2))
                        }
                }
            Case3:
                return first&&isMatch(s.substr(1),p.substr(1));
        */
        //if (s.empty()) {
        //    if (p.empty()) return true;
        //    if (p.size() >= 2 && p[1] == '*') return p.substr(2).empty();
        //    else return false;
        //}
        pair<string, string> P = make_pair(s, p);
        if (ms.count(P)) return ms[P];
        if (p.empty()) {
            ms[P] = s.empty();;
            return ms[P];
        }  
        bool first = !s.empty()&&(s[0] == p[0] || p[0] == '.');
        if (p.size() >= 2 && p[1] == '*') {
            if (isMatch(s, p.substr(2))) {
                ms[P] = true;
                return ms[P];
            }
            if (first) {
                ms[P] = isMatch(s.substr(1), p);
                return ms[P];
            }
        }
        ms[P] = first && isMatch(s.substr(1), p.substr(1));
        return ms[P];
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the s:" << endl;
        string s;
        getline(cin, s);
        if (s == "q") break;
        s = s.substr(1, s.size() - 2);
        cout << "Enter the p:" << endl;
        string p;
        getline(cin, p);
        if (p == "q") break;
        p = p.substr(1, p.size() - 2);
        cout << "Res: " << S1.isMatch(s, p) << endl;
    }
}