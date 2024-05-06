#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        // write code here
        string ans = "";
        string token = "%20";
        for (char& c : s) {
            if (c == ' ') {
                ans += token;
            }
            else {
                ans += c;
            }
        }
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter the string s:" << endl;
        string s;
        getline(cin, s);
        if (s == "q") break;
        s = s.substr(1, s.size() - 2);
        cout <<"Res: " << S1.replaceSpace(s) << endl;
    }
}