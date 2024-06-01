#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    //bool isValid(string& s) {
    //    int cntR = 0;
    //    for (int i = 0; i < s.size(); i++) {
    //        /*   i
    //            "()())()"
    //        */
    //        if (s[i] == '(') cntR++;
    //        else if (s[i] == ')') {
    //            if (cntR == 0) return false;
    //            cntR--;
    //        }
    //    }
    //    // cout<<"cntR:"<<cntR<<endl;
    //    return cntR == 0;
    //}
    bool isValid(string& s) {
        if (s[0] == ')') return false;
        string ans = "";
        for (char& c : s) {
            if (isalpha(c)) continue;
            if (c == ')') {
                if (!ans.empty() && ans.back() == '(') ans.pop_back();
                else ans.push_back(c);

            }
            else {
                ans.push_back(c);
            }
        }
        return ans.empty();
    }
    vector<string> removeInvalidParentheses(string s) {
        if (isValid(s)) return { s };
        queue<string> Q;
        unordered_set<string> hset;
        vector<string> ans;
        Q.push(s);
        bool found = false;
        while (!Q.empty()) {
            int size = Q.size();
            while (size--) {
                string s = Q.front();
                Q.pop();
                for (int i = 0; i < s.size(); ++i) {
                    if (isalpha(s[i])) continue;
                    string newS = s.substr(0, i) + s.substr(i + 1);
                    if (hset.count(newS)) continue;
                    if (isValid(newS)) {
                        found = true;
                        ans.push_back(newS);
                    }
                    else {
                        Q.push(newS);
                    }
                    hset.insert(newS);
                }
            }
            if (found) break;
        }
        if (ans.empty()) return { "" };
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter s:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        vector<string> res = S1.removeInvalidParentheses(In);
        cout << "Res: ";
        for (string& s : res) {
            cout << s << ",";
        }
        cout << endl;
    }
}