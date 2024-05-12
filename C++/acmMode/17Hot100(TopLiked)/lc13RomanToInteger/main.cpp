#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        /*
        *   I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000
            Input: s = "MCMXCIV"
            Output: 1994
            Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
            Just need to judge if the current char is larger or smaller then next one.
        */
        unordered_map<char, int> ms;
        ms['I'] = 1;
        ms['V'] = 5;;
        ms['X'] = 10;
        ms['L'] = 50;
        ms['C'] = 100;
        ms['D'] = 500;
        ms['M'] = 1000;
        int ans = 0;
        for (int i = 0; i < s.size()-1; ++i) {
            if (ms[s[i]] >= ms[s[i + 1]]) {
                ans += ms[s[i]];
            }
            else {
                ans -= ms[s[i]];
            }
        }
        ans += ms[s[s.size() - 1]];
        return ans;
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
        cout << "Res: " << S1.romanToInt(s) << endl;
    }
}