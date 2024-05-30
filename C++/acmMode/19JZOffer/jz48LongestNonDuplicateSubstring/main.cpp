#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // write code here
        /*   l
            "abcabcbb"
                r
             ans: 3 
             mset: abc
        */
        unordered_set<char> mset;
        int l = 0, r = 0;
        int ans = 0;
        while (r < s.size()) {
            if (mset.count(s[r])==0) {
                ans = max(ans, r-l+1);
                mset.insert(s[r]);
                r++;
            }
            while (mset.count(s[r])) {
                mset.erase(s[l]);
                l++;
            }
        }
        return ans;
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
        cout << "Res: " << S1.lengthOfLongestSubstring(In) << endl;
    }
}