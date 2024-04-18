#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*
            Input: strs = ["flower","flow","flight"]
            Output: "fl"
        */
        auto f = [](const string& a, const string& b)->bool {
            return a.size() < b.size();
        };
        sort(strs.begin(), strs.end(), f);
        int j = 0;
        bool notMatch = false;
        for (j; j < strs[0].size(); ++j) {
            for (int i = 1; i < strs.size(); ++i) {
                if (strs[i - 1][j] != strs[i][j]) {
                    notMatch = true;
                    break;
                }
            }
            if (notMatch) {
                break;
            }
        }
        return strs[0].substr(0, j);
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        string Ss;
        cout << "Enter the strs:" << endl;
        getline(cin, Ss);
        if (Ss == "q") break;
        Ss = Ss.substr(2, Ss.size() - 4);
        vector<string> strs;
        if (!Ss.empty()) {
            size_t pos = 0;
            while ((pos=Ss.find("\",\"")) != string::npos) {
                strs.push_back(Ss.substr(0, pos));
                Ss = Ss.substr(pos + 3);
            }
        }
        strs.push_back(Ss);
        cout << "Res: " << S1.longestCommonPrefix(strs)<<endl;
;    }
}