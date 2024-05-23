#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        /*
            Input: s = "3[a2[c]]"
            [3
                str: a+     
                        2 * 
                            c
            Output: "accaccacc"
        */
        int start = 0;
        return dfs(start, s);
    }
    string dfs(int & start, string & s) {
        string str;
        while (start < s.size()) {
            if (isdigit(s[start])) {
                int l = start;
                while (start < s.size() && isdigit(s[start])) {
                    start++;
                }
                int n = stoi(s.substr(l, start - l));
                if (s[start] == '[') start++;
                string tmp = dfs(start, s);
                while (n--) {
                    str += tmp;
                }
            }
            else if (isalpha(s[start])) {
                while (start < s.size() && isalpha(s[start])) {
                    str.push_back(s[start]);
                    start++;
                }
            }
            else if (s[start] == ']') {
                start++;
                return str;
            }
        }
        return str;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the s:" << endl;
        string In;
        getline(cin, In);
        if (In == "q") break;
        In = In.substr(1, In.size() - 2);
        cout <<"Res:"<< S1.decodeString(In) << endl;
    }
}