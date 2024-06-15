#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if (str.size() == 0) return str;
        // write code here
        n %= str.size();
        string ans = str.substr(n);
        ans += str.substr(0, n);
        return ans;
    }
};

int main(int argc, char* argv[]) {
    while (true) {
        Solution S1;
        cout << "Enter string str:" << endl;
        string S;
        getline(cin, S);
        if (S == "q") break;
        cout << "Enter n:" << endl;
        string N;
        getline(cin, N);
        if (N == "q") break;
        S = S.substr(1, S.size() - 2);
        int n = stoi(N);
        cout << "Res: " << S1.LeftRotateString(S, n) << endl;
    }
}